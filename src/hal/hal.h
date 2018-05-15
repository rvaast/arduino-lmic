/*******************************************************************************
 * Copyright (c) 2015 Matthijs Kooijman
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * This the HAL to run LMIC on top of the Arduino environment.
 *******************************************************************************/
#ifndef _hal_hal_h_
#define _hal_hal_h_

static const int NUM_DIO = 3;

struct lmic_pinmap {
    u1_t nss;
    u1_t rxtx;
    u1_t rst;
    u1_t dio[NUM_DIO];
    u1_t rxtx_rx_active;
    s1_t rssi_cal;              // byte 7: cal in dB -- added to RSSI
                                //   measured prior to decision.
                                //   Must include noise guardband!
    u4_t spi_freq;
};

// Use this for any unused pins.
const u1_t LMIC_UNUSED_PIN = 0xff;

// Declared here, to be defined and initialized by the application
// use os_init_ex() if you want not to use a const table.
extern const lmic_pinmap lmic_pins;

#endif // _hal_hal_h_
