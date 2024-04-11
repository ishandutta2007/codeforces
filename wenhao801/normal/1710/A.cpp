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

int a[100100];

int main() {
    int T = read();
    while (T--) {
        int n = read(), m = read(), K = read(), i, j;
        for (i = 1; i <= K; i++) a[i] = read();
        long long cnt = 0, ex = 0;
        for (i = 1; i <= K; i++) if (a[i] >= 2 * n) cnt += a[i] / n, ex += a[i] / n > 2;
        if (cnt >= m && !((cnt - m) % 2 == 1 && !ex)) { puts("Yes"); continue; }
        cnt = ex = 0;
        for (i = 1; i <= K; i++) if (a[i] >= 2 * m) cnt += a[i] / m, ex += a[i] / m > 2;
        if (cnt >= n && !((cnt - n) % 2 == 1 && !ex)) puts("Yes"); else puts("No");
    }
    return 0;
}