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

int main () {
    int t = read();
    while (t--) {
        int n = read(), s = 0, Max = 0;
        while (n--) { int x = read(); s += x, Max = max(Max, x); }
        if ((Max << 1) > s) puts("T"); else puts((s & 1) ? "T" : "HL");
    }
    return 0;
}