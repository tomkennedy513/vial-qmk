// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _MAIN,
    _SYM,
    _NUM,
    _FN,
    _HJKL,
};

enum custom_keycodes {
    CTRL_SPACE = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT(
        KC_Q,        KC_W,        KC_E,        KC_R,            KC_T,                                 KC_Y,          KC_U,        KC_I,        KC_O,        CTRL_SPACE,
        SFT_T(KC_A), CTL_T(KC_S), ALT_T(KC_D), CMD_T(KC_F),     KC_G,                                 KC_H,          CMD_T(KC_J), ALT_T(KC_K), CTL_T(KC_L), SFT_T(KC_P),
        KC_Z,        KC_X,        KC_C,        KC_V,            KC_B,    OSM(MOD_MEH), OSM(MOD_HYPR), KC_N,          KC_M,        KC_COMM,     KC_DOT,      KC_ENT,
        KC_NO,       KC_NO,       KC_NO,       LT(_FN, KC_ESC), KC_BSPC, OSL(_SYM),    OSL(_NUM),     SFT_T(KC_SPC), KC_TAB,      KC_ESC,      KC_NO,       KC_NO),

    [_SYM] = LAYOUT(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_PLUS, KC_EQL,  KC_QUES, KC_PIPE, KC_BSLS,
        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                     KC_UNDS, KC_MINS, KC_QUOT, KC_DQUO, KC_SLSH,
        KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, TO(_MAIN), KC_TRNS, KC_TRNS, KC_SCLN, KC_COLN, KC_GRV,  KC_TILD, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_NUM] = LAYOUT(
        KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,                      LCTL(LSFT(KC_TAB)), KC_PGDN, KC_PGUP, LCTL(KC_TAB), KC_NO,
        KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,                       KC_LEFT,           KC_DOWN, KC_UP,   KC_RGHT,      KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(_MAIN), KC_TRNS, KC_TRNS, KC_NO,             KC_NO,   KC_COMM, KC_DOT,       KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NO,   KC_NO,   KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS),

    [_FN] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                      KC_NO,   KC_LCMD, KC_LALT, KC_LCTL, KC_LSFT,
        KC_F11,  KC_F12,  KC_NO,   KC_NO,   TO(_MAIN), KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};
// clang-format on

const uint16_t PROGMEM esc_combo[]  = {OSL(_SYM), OSL(_NUM), COMBO_END};
const uint16_t PROGMEM tab_combo[]  = {KC_BSPC, SFT_T(KC_SPC), COMBO_END};
combo_t                key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(tab_combo, KC_TAB),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTRL_SPACE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(" ")); // send control space
            }
            break;
    }
    return true;
};
