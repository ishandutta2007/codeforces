#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n, m;

struct rua { int l, r, t; } a[101] = {};

bool cmp (rua x, rua y) { return x.t < y.t; }

signed main () {
    int T = read();
    while (T--) {
        n = read(), m = read();
        int i, j;
        for (i = 1; i <= n; i++) a[i].t = read(), a[i].l = read(), a[i].r = read();
        sort(a + 1, a + n + 1, cmp);
        int l = m, r = m; bool f = false;
        int las = 0;
        for (i = 1; i <= n; i++) {
            int tmp = a[i].t, L = a[i].l, R = a[i].r;
            //while (a[i + 1].t == tmp) i++, L = max(L, a[i].l), R = min(R, a[i].r);
            if (L > R) { puts("NO"); f = true; break; }
            if (L > r + (tmp - las)) { puts("NO"); f = true; break; }
            if (l - (tmp - las) > R) { puts("NO"); f = true; break; }
            l = max(l - tmp + las, L), r = min(r + tmp - las, R);
            las = a[i].t;
        }
        if (!f) puts("YES");
    }
    return 0;
}