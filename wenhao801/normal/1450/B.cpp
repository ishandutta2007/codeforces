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

int n, K, a[110], b[120];

int main() {
    int T = read(); while (T--) {
        n = read(), K = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read(), b[i] = read();
        if (n == 1) puts("0");
        else {
            for (i = 1; i <= n; i++) {
                int mx = 0;
                for (j = 1; j <= n; j++) mx = max(mx, abs(a[i] - a[j]) + abs(b[i] - b[j]));
                if (mx <= K) { puts("1"); break; }
            }
            if (i > n) puts("-1");
        }
    }
    return 0;
}