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
int n, m, fa[MAXN], siz[MAXN], top, tmp[MAXN];
int gf (int x) { return fa[x] == x ? x : (fa[x] = gf(fa[x])); }

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) fa[i] = i;
    int y = 0;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read();
        if (gf(u) != gf(v)) fa[gf(u)] = gf(v); else ++y;
        top = 0;
        for (j = 1; j <= n; j++) tmp[j] = 0;
        for (j = 1; j <= n; j++) ++tmp[gf(j)];
        sort(tmp + 1, tmp + n + 1); int ans = 0;
        for (j = n; j >= n - y && j >= 1; j--) ans += tmp[j];
        printf("%d\n", ans - 1);
    }
    return 0;
}