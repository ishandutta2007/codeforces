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

const int MAXN = 100100;
int n, a[MAXN];

int main() {
    int T = read();
    while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        if (n == 3 && a[2] % 2 == 1) { puts("-1"); continue; }
        int cnt = 0; bool ok = 0;
        long long s = 0;
        for (i = 2; i < n; i++) cnt += a[i] & 1, ok |= a[i] != 1, s += a[i];
        if (!ok) { puts("-1"); continue; }
        printf("%lld\n", (s + cnt) >> 1);
    }
    return 0;
}