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
int r, n, a[MAXN], b[MAXN], t[MAXN];
int f[MAXN], pre[MAXN];

int main() {
    r = read(), n = read(); int i, j;
    a[0] = b[0] = 1, t[0] = 0;
    for (i = 1; i <= n; i++) {
        t[i] = read(), a[i] = read(), b[i] = read();
        f[i] = -1e9;
        for (j = i - 1; j >= 0; j--) {
            if (abs(a[i] - a[j]) + abs(b[i] - b[j]) <= t[i] - t[j]) f[i] = max(f[i], f[j] + 1);
            if (t[i] - t[j] >= 2 * r) { f[i] = max(f[i], pre[j] + 1); break; }
        }
        pre[i] = max(pre[i - 1], f[i]);
    }
    printf("%d\n", pre[n]);
    return 0;
}