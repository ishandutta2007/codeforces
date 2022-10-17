#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int main() {
    bool cur = 0;
    int n = read(); while (n--) {
        int x = read(), sgn = 1;
        if (x < 0) sgn = -1, x = -x;
        if (x & 1) {
            int p = x >> 1, q = x - p; p *= sgn, q *= sgn;
            printf("%d\n", cur ? min(p, q) : max(p, q)); cur ^= 1;
        }
        else printf("%d\n", (x >> 1) * sgn);
    }
    return 0;
}