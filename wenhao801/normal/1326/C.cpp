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

const int MAXN = 200020;
int n, m, a[MAXN];

int main() {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();

    int last = 0, way = 1;
    long long ans = 0;
    for (i = 1; i <= n; i++) if (a[i] >= n - m + 1) {
        ans += a[i]; if (last) way = 1ll * way * (i - last) % 998244353;
        last = i;
    }
    printf("%lld %d\n", ans, way);
    return 0;
}