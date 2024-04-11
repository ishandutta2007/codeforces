#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
const int MAXN = 100100, mod = 1e9 + 7;
int n, k;
int fa[MAXN << 1];
int gf (int x) { if (fa[x] == x) return x; return fa[x] = gf(fa[x]); }
int op (int x) { return (x > n + 2) ? x - (n + 2) : x + (n + 2); }

int main () {
    n = read(); k = read();
    int i, j;
    for (i = 1; i <= ((n + 2) << 1); i++) fa[i] = i;
    for (i = 1; i <= k; i++) {
        int u = read(), v = read(); char c[2]; scanf("%s", c);
        int x = abs(u - v) + 1, y = min(u + v - 1, 2 * n + 1 - u - v) + 2;
        if (c[0] == 'x') {
            if (gf(x) != gf(y)) fa[gf(x)] = gf(y);
            if (gf(op(x)) != gf(op(y))) fa[gf(op(x))] = gf(op(y));
        }
        else {
            if (gf(x) != gf(op(y))) fa[gf(x)] = gf(op(y));
            if (gf(op(x)) != gf(y)) fa[gf(op(x))] = gf(y);
        }
        if (gf(x) == gf(op(x)) || gf(y) == gf(op(y))) { puts("0"); return 0; }
    }
    int ans = 0; for (i = 1; i <= ((n + 2) << 1); i++) ans += gf(i) == i;
    ans -= 4; ans >>= 1; for (i = 1, j = 1; i <= ans; i++, j = 2ll * j % mod);
    printf("%d\n", j);
    return 0;
}