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

const int MAXN = 1010;
int n, m, K, fa[MAXN], siz[MAXN];
inline int gf (int x) { return fa[x] == x ? x : (fa[x] = gf(fa[x])); }
int a[MAXN], b[MAXN];

int main () {
    n = read(), m = read(), K = read(); int i, j;
    for (i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
    for (i = 1; i <= K; i++) a[i] = read();
    for (i = 1; i <= m; i++) {
        int u = read(), v = read();
        if (gf(u) != gf(v)) siz[gf(v)] += siz[gf(u)], fa[gf(u)] = gf(v);
    }
    for (i = 1; i <= K; i++) b[gf(a[i])] = 1;
    int left = n, mx = 0, ans = 0;
    for (i = 1; i <= n; i++) if (gf(i) == i) {
        if (b[i]) ans += siz[i] * (siz[i] - 1) / 2, mx = max(mx, siz[i]), left -= siz[i];
    }
    ans -= mx * (mx - 1) / 2;
    mx += left;
    ans += mx * (mx - 1) / 2;
    printf("%d\n", ans - m);
    return 0;
}