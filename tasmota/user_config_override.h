/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS     MY_IP                // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY        MY_GW                // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS            MY_DNS               // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

#ifdef MY_DNS2
#undef  WIFI_DNS2
#define WIFI_DNS2           MY_DNS2              // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!!
*/

#ifdef FIRMWARE_LVGL_THERMOSTAT

#ifdef THERMOSTAT_SENSOR_NAME
  #undef THERMOSTAT_SENSOR_NAME
#endif
#define THERMOSTAT_SENSOR_NAME  "BME280"

//#define DISABLE_PSRAMCHECK
//#undef BOARD_HAS_PSRAM
#undef DISABLE_PSRAMCHECK

#undef CONFIG_BT_ENABLED

#ifndef CODE_IMAGE_STR
  #define CODE_IMAGE_STR "lvgl-haspmota"
#endif

#undef MODULE
#define MODULE                 WEMOS             // [Module] Select default module from tasmota_template.h
#undef FALLBACK_MODULE
#define FALLBACK_MODULE        WEMOS             // [Module2] Select default module on fast reboot where USER_MODULE is user template

#undef USE_TASMESH                               // Disable Tasmota Mesh using ESP-NOW (+11k code)
#undef USE_ARDUINO_OTA                           // Disable support for Arduino OTA
#undef USE_INFLUXDB                              // Disable influxdb support (+5k code)
#undef USE_DOMOTICZ                              // Disable Domoticz
#undef USE_HOME_ASSISTANT                        // Disable Home Assistant
#define USE_TASMOTA_DISCOVERY                     // Disable Tasmota Discovery support (+2k code)
#undef USE_TELEGRAM                              // Disable support for Telegram protocol (+49k code, +7.0k mem and +4.8k additional during connection handshake)
#undef USE_KNX                                   // Disable KNX IP Protocol Support
#undef USE_DALI                                  // Disable support for DALI gateway (+5k code)
#undef USE_GPIO_VIEWER                           // Enable GPIO Viewer to see realtime GPIO states (+5k6 code)
#undef USE_EMULATION                             // Disable Wemo or Hue emulation
#undef USE_EMULATION_HUE                         // Disable Hue Bridge emulation for Alexa (+14k code, +2k mem common)
#undef USE_EMULATION_WEMO                        // Disable Belkin WeMo emulation for Alexa (+6k code, +2k mem common)
#undef USE_DISCOVERY                             // Disable Discovery services for both MQTT and web server

#undef USE_MHZ19                                 // Disable support for MH-Z19 CO2 sensor
#undef USE_SENSEAIR                              // Disable support for SenseAir K30, K70 and S8 CO2 sensor
#undef USE_PMS5003                               // Disable support for PMS5003 and PMS7003 particle concentration sensor
#undef USE_NOVA_SDS                              // Disable support for SDS011 and SDS021 particle concentration sensor
#undef USE_HPMA                                  // Disable support for Honeywell HPMA115S0 particle concentration sensor
#undef USE_SR04                                  // Disable support for HC-SR04 ultrasonic devices (+1k code)
#undef USE_ME007                                 // Disable support for ME007 ultrasonic devices (+1k5 code)
#undef USE_DYP                                   // Disable support for DYP ME-007 ultrasonic distance sensor, serial port version (+0k5 code)
#undef USE_SERIAL_BRIDGE                         // Disable support for software Serial Bridge
#undef USE_MODBUS_BRIDGE                         // Disable support for software Modbus Bridge (+3k code)
#undef USE_TCP_BRIDGE                            // DIsable support for Serial to TCP bridge (+1.3k code)
#undef USE_MP3_PLAYER                            // Disable DFPlayer Mini MP3 Player RB-DFR-562 commands: play, volume and stop
#undef USE_AZ7798                                // Disable support for AZ-Instrument 7798 CO2 datalogger
#undef USE_PN532_HSU                             // Disable support for PN532 using HSU (Serial) interface (+1k8 code, 140 bytes mem)
#undef USE_ZIGBEE                                // Disable serial communication with Zigbee CC2530 flashed with ZNP
#undef USE_RDM6300                               // Disable support for RDM6300 125kHz RFID Reader (+0k8)
#undef USE_IBEACON                               // Disable support for bluetooth LE passive scan of ibeacon devices (uses HM17 module)
#undef USE_GPS                                   // Disable support for GPS and NTP Server for becoming Stratus 1 Time Source (+ 3.1kb flash, +132 bytes RAM)
#undef USE_HM10                                  // (ESP8266 only) Disable support for HM-10 as a BLE-bridge for the LYWSD03 (+5k1 code)
#undef USE_BLE_ESP32                             // (ESP32 only) Disable support for native BLE on ESP32 - use new driver
#undef USE_MI_ESP32                              // (ESP32 only) Disable support for ESP32 as a BLE-bridge (+9k2 mem, +292k flash)
#undef USE_HRXL                                  // Disable support for MaxBotix HRXL-MaxSonar ultrasonic range finders (+0k7)
#undef USE_TASMOTA_CLIENT                        // Disable support for Arduino Uno/Pro Mini via serial interface including flashing (+2k3 code, 44 mem)
#undef USE_OPENTHERM                             // Disable support for OpenTherm (+15k code)
#undef USE_MIEL_HVAC                             // Disable support for Mitsubishi Electric HVAC serial interface (+5k code)
#undef USE_PROJECTOR_CTRL                        // Disable support for LCD/DLP Projector serial control interface
#undef USE_AS608                                 // Disable support for AS608 optical and R503 capacitive fingerprint sensor (+3k4 code)
#undef USE_TFMINIPLUS                            // Disable support for TFmini Plus (TFmini, TFmini-S) LiDAR modules via UART interface (+0k8)
#undef USE_HRG15                                 // Disable support for Hydreon RG-15 Solid State Rain sensor (+1k5 code)
#undef USE_VINDRIKTNING                          // Disable support for IKEA VINDRIKTNING particle concentration sensor (+0k6 code)
#undef USE_LOX_O2                                // Disable support for LuminOx LOX O2 Sensor

#undef USE_DHT                                   // Disable support for DHT11, AM2301 (DHT21, DHT22, AM2302, AM2321) and SI7021 Temperature and Humidity sensor
#undef USE_MAX31855                              // Disable MAX31855 K-Type thermocouple sensor using softSPI
#undef USE_MAX31865                              // Disable support for MAX31865 RTD sensors using softSPI
#undef USE_LMT01                                 // Disable support for TI LMT01 temperature sensor, count pulses on single GPIO (+0k5 code)
#undef USE_IR_REMOTE                             // Disable IR driver
#undef USE_IR_REMOTE_FULL
#undef USE_TM1638                                // Disable support for TM1638 switches copying Switch1 .. Switch8
#undef USE_HX711                                 // Disable support for HX711 load cell
#undef USE_TX20_WIND_SENSOR                      // Disable support for La Crosse TX20 anemometer
#undef USE_TX23_WIND_SENSOR                      // Disable support for La Crosse TX23 anemometer
#undef USE_WINDMETER                             // Disable support for analog anemometer (+2k2 code)
#undef USE_RC_SWITCH                             // Disable support for RF transceiver using library RcSwitch
#undef USE_RF_SENSOR                             // Disable support for RF sensor receiver (434MHz or 868MHz) (+0k8 code)
#undef USE_HRE                                   // Disable support for Badger HR-E Water Meter (+1k4 code)
#undef USE_A4988_STEPPER                         // Disable support for A4988_Stepper
#undef USE_PROMETHEUS                            // Disable support for https://prometheus.io/ metrics exporting over HTTP /metrics endpoint
#undef DEBUG_THEO                                // Disable debug code
#undef USE_DEBUG_DRIVER                          // Disable debug code
#undef USE_AC_ZERO_CROSS_DIMMER                  // Disable support for AC_ZERO_CROSS_DIMMER
#undef USE_SCD30                                 // [I2cDriver29] Disable Sensiron SCd30 CO2 sensor (I2C address 0x61) (+3k3 code)
#undef USE_SCD40                                 // [I2cDriver62] Disable Sensiron SCd40/Scd41 CO2 sensor (I2C address 0x62) (+3k5 code)
#undef USE_SPS30                                 // [I2cDriver30] Disable Sensiron SPS30 particle sensor (I2C address 0x69) (+1.7 code)
#undef USE_ADE7880                               // [I2cDriver65] Disable ADE7880 Energy monitor as used on Shelly 3EM (I2C address 0x38) (+3k8)

#undef USE_TSL2561                            // [I2cDriver16] Disable TSL2561 sensor (I2C address 0x29, 0x39 or 0x49) using library Joba_Tsl2561 (+2k3 code)
#undef USE_TSL2591                            // [I2cDriver40] Disable TSL2591 sensor (I2C address 0x29) using library Adafruit_TSL2591 (+1k6 code)

#undef USE_BP1658CJ                             // Disable support for BP1658CJ RGBCW led control as used in Orein OS0100411267 Bulb
#undef USE_BP5758D                              // Disable support for BP5758D RGBCW led control as used in some Tuya lightbulbs (+0k8 code)
#undef USE_DEEPSLEEP                             // Disable support for deepsleep (+1k code)
#undef USE_DISPLAY_MODES1TO5                     // Disable display mode 1 to 5 in addition to mode 0
#undef USE_IMPROV                                // Disable support for IMPROV serial protocol as used by esp-web-tools (+2k code)
#undef USE_LIGHT                                 // Disable support for light control
#undef USE_PING                                  // Disable Ping command (+2k code)
#undef USE_TIMERS                               // Disable support for up to 16 timers (+2k2 code)
  #undef USE_TIMERS_WEB                         // Disable timer webpage support (+4k5 code)
  #undef USE_SUNRISE                            // Disable support for Sunrise and sunset tools (+16k)
/*  USE_UFILESYS
  USE_WEBSERVER
  WEBSERVER_ADVERTISE
*/

#define USE_THERMOSTAT                            // Disable support for Thermostat
#define THERMOSTAT_CONTROLLER_OUTPUTS 1

#define USE_ESP32_SENSORS
#define USE_UFILESYS
#define GUI_TRASH_FILE
#undef GUI_EDIT_FILE
#define USE_PING
#undef USE_AUTOCONF
#define USE_BERRY                                // Enable Berry scripting language
  #undef USE_BERRY_PYTHON_COMPAT                // Enable by default `import python_compat`
  #define USE_BERRY_TIMEOUT             4000     // Timeout in ms, will raise an exception if running time exceeds this timeout
  #undef USE_BERRY_PSRAM                        // Allocate Berry memory in PSRAM if PSRAM is connected - this might be slightly slower but leaves main memory intact
  #define USE_BERRY_IRAM                         // Allocate some data structures in IRAM (which is ususally unused) when possible and if no PSRAM is available
  #define USE_BERRY_FAST_LOOP_SLEEP_MS  5        // Minimum time in milliseconds to before calling again `tasmota.fast_loop()`, a smaller value will consume more CPU (min 1ms)
  // #define USE_BERRY_DEBUG                        // Compile Berry bytecode with line number information, makes exceptions easier to debug. Adds +8% of memory consumption for compiled code
  //   #define UBE_BERRY_DEBUG_GC                   // Print low-level GC metrics
  // #define USE_BERRY_INT64                        // Add 64 bits integer support (+1.7KB Flash)
  #undef USE_WEBCLIENT                          // Enable `webclient` to make HTTP/HTTPS requests. Can be disabled for security reasons.
    // #define USE_WEBCLIENT_HTTPS                  // Enable HTTPS outgoing requests based on BearSSL (much ligher then mbedTLS, 42KB vs 150KB) in insecure mode (no verification of server's certificate)
                                                 // Note that only one cipher is enabled: ECDHE_RSA_WITH_AES_128_GCM_SHA256 which is very commonly used and highly secure
    #define USE_BERRY_WEBCLIENT_USERAGENT  "TasmotaClient" // default user-agent used, can be changed with `wc.set_useragent()`
    #define USE_BERRY_WEBCLIENT_TIMEOUT  2000    // Default timeout in milliseconds
    #undef USE_BERRY_LEDS_PANEL                 // Add button to dynamically load the Leds Panel from a bec file online
    //#define USE_BERRY_LEDS_PANEL_URL             "http://ota.tasmota.com/tapp/leds_panel.bec"
    //#define USE_BERRY_PARTITION_WIZARD           // Add a button to dynamically load the Partion Wizard from a bec file online (+1.3KB Flash)
    //#define USE_BERRY_PARTITION_WIZARD_URL      "http://ota.tasmota.com/tapp/partition_wizard.bec"
    //#define USE_BERRY_GPIOVIEWER                 // Add a button to dynamocally load the GPIO Viewer from a bec file online
    //#define USE_BERRY_GPIOVIEWER_URL            "http://ota.tasmota.com/tapp/gpioviewer.bec"
  #undef USE_BERRY_TCPSERVER                    // Enable TCP socket server (+0.6k)
  #undef USE_BERRY_ULP                          // Enable ULP (Ultra Low Power) support (+4.9k)
  // Berry crypto extensions below:
  #undef USE_BERRY_CRYPTO_AES_GCM               // enable AES GCM 256 bits
  // #define USE_BERRY_CRYPTO_AES_CCM               // enable AES CCM 128 bits
  // #define USE_BERRY_CRYPTO_AES_CTR               // enable AES CTR 256 bits
  // #define USE_BERRY_CRYPTO_EC_P256               // enable EC P256r1
  // #define USE_BERRY_CRYPTO_EC_C25519             // enable Elliptic Curve C C25519
  #undef USE_BERRY_CRYPTO_SHA256                // enable SHA256 hash function
  #undef USE_BERRY_CRYPTO_HMAC_SHA256           // enable HMAC SHA256 hash function
#undef USE_ETHERNET

#define USE_TLS
#define USE_WEBSERVER
#define USE_WEBCLIENT
#undef USE_WEBCLIENT_HTTPS
#undef USE_MQTT_TLS

#define USE_LVGL
  #undef SET_ESP32_STACK_SIZE
  #define SET_ESP32_STACK_SIZE (24 * 1024)
  #undef USE_LVGL_FREETYPE
  #undef LV_USE_TABLE
  //#undef LV_USE_METER
  #undef LV_USE_TEXTAREA
  #undef LV_USE_CALENDAR
  #undef LV_USE_COLORWHEEL
  //#undef LV_USE_MSGBOX
  #undef LV_USE_KEYBOARD

#undef USE_I2S
#define USE_SPI

#define USE_DISPLAY
#define USE_UNIVERSAL_DISPLAY
#define USE_UNIVERSAL_TOUCH
//#define USE_XPT2046
//#define USE_FT5206
//#define USE_GT911
//#define USE_CST816S
#define USE_DISPLAY_LVGL_ONLY
#undef USE_EPD_FONTS

//#undef USE_DISPLAY_MODES1TO5
#undef USE_DISPLAY_LCD
#undef USE_DISPLAY_MATRIX
#undef USE_DISPLAY_SEVENSEG

#define USE_ENHANCED_GUI_WIFI_SCAN

#undef USE_SDCARD

#undef USE_ARMTRONIX_DIMMERS                    // Disable support for Armtronix Dimmers (+1k4 code)
#undef USE_SONOFF_IFAN                          // Disable support for Sonoff iFan02 and iFan03 (+2k code)
#define USE_BUZZER                               // Add support for a buzzer (+0k6 code)
#undef USE_EMULATION_WEMO

#define USE_I2C                                  // I2C using library wire (+10k code, 0k2 mem, 124 iram)

#define USE_BMP                                // [I2cDriver10] Enable BMP085/BMP180/BMP280/BME280 sensors (I2C addresses 0x76 and 0x77) (+4k4 code)

#undef USE_NRF24                              // Disable SPI support for NRF24L01(+) (+2k6 code)
#undef USE_MIBLE                              // BLE-bridge for some Mijia-BLE-sensors (+4k7 code)

#define USE_LED                                // needed for multi-PWM support (buzzer + backlight)
#undef USE_LIGHT_PALETTE                       // No support for color palette (+0k7 code)
#undef USE_LIGHT_VIRTUAL_CT                    // No support for Virtual White Color Temperature (+1.1k code)

#undef USE_ADC
#undef USE_PWM_DIMMER
#undef USE_PWM_DIMMER_REMOTE
#undef USE_TUYA_MCU
#undef USE_ARILUX_RF
#undef USE_DS18x20
#define USE_BMP                                // [I2cDriver10] Enable BMP085/BMP180/BMP280/BME280 sensors (I2C addresses 0x76 and 0x77) (+4k4 code)
#undef USE_BME68X                              // Support for BME680/BME688 sensor using Bosch BME68x library (+6k9 code)
#undef USE_BH1750
#undef USE_WS2812
#undef USE_ENERGY_SENSOR
#undef USE_SHUTTER
#undef USE_DEVICE_GROUPS

#define CORE32SOLO1 0

#endif

#endif  // _USER_CONFIG_OVERRIDE_H_
