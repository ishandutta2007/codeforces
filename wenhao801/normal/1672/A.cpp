#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int sg[55], buc[55];

int main () {
    int i, j;
    for (i = 2; i <= 50; i++) {
        memset(buc, 0, sizeof buc);
        for (j = 1; j < i; j++) buc[sg[j] ^ sg[i - j]] = 1;
        for (j = 0; buc[j]; j++);
        sg[i] = j;
    }
    int T = read(); while (T--) {
        int n = read(), s = 0;
        while (n--) { int x = read(); s ^= sg[x]; }
        puts(s ? "errorgorn" : "maomao90");
    }
    return 0;
}