#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

int main () {
    int T = read(); while (T--) {
        int n = read(), i, j; bool all0 = 1; int cur = 0;
        for (i = 1; i <= n; i++) {
            int x = read(); all0 &= !x;
            if (x) {
                if (cur == 2) cur = 3;
                else if (!cur) cur = 1;
            }
            if (!x && cur == 1) cur = 2;
        }
        if (all0) puts("0"); else if (cur <= 2) puts("1"); else puts("2");
    }
    return 0;
}