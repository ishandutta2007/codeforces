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
    int T = read(); while (T--) {
        int n = read(), ans = 0, last = -1;
        for (int i = 1; i <= n; i++) {
            int x = read();
            if (last == -1) last = x;
            else ans |= last != x;
        }
        if (!ans) printf("%d\n", n); else printf("%d\n", 1);
    }
    return 0;
}