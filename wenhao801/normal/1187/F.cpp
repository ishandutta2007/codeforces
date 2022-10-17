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

const int mod = 1e9 + 7, MAXN = 200200;
inline int add (int u, int v) { u += v; if (u > mod) u -= mod; return u; }
inline int dec (int u, int v) { u -= v; if (u < 0) u += mod; return u; }
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }
    return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

int l[MAXN], r[MAXN], n;

int len (int x) { return r[x] - l[x] + 1; }
int And (int l1, int r1, int l2, int r2) { if (l1 > l2) swap(l1, l2), swap(r1, r2); r1 = min(r1, r2); return max(0, r1 - l2 + 1); }
int And (int l1, int r1, int l2, int r2, int l3, int r3) {
    if (l1 > l2) swap(l1, l2), swap(r1, r2);
    r1 = min(r1, r2); l1 = max(l1, l2);
    if (l1 > r1) l1 = r1 = 0;
    return And(l1, r1, l3, r3);
}
int f (int x) { return 1ll * dec(1ll * len(x) * len(x + 1) % mod, And(l[x], r[x], l[x + 1], r[x + 1])) * inv(1ll * len(x) * len(x + 1) % mod) % mod; }

int main () {
    n = read() + 1; int i, j;
    l[1] = r[1] = 0;
    for (i = 2; i <= n; i++) l[i] = read();
    for (i = 2; i <= n; i++) r[i] = read();
    int ans = 0, sav = 0;
    for (i = 1; i <= n - 1; i++) sav = add(sav, f(i));
    for (i = 1; i <= n - 2; i++) ans = add(ans, 1ll * 
        dec(
            add(1ll * len(i) * len(i + 1) % mod * len(i + 2) % mod, And(l[i], r[i], l[i + 1], r[i + 1], l[i + 2], r[i + 2])), 
            add(1ll * len(i + 2) * And(l[i], r[i], l[i + 1], r[i + 1]) % mod, 1ll * len(i) * And(l[i + 1], r[i + 1], l[i + 2], r[i + 2]) % mod)
        ) * inv(1ll * len(i) * len(i + 1) % mod * len(i + 2) % mod) % mod);
    ans = 2ll * ans % mod; ans = add(ans, sav);
    for (i = 1; i <= n - 1; i++) {
        int tmp = sav;
        for (j = i - 1; j <= i + 1; j++) if (j >= 1 && j <= n - 1) tmp = dec(tmp, f(j));
        ans = add(ans, 1ll * f(i) * tmp % mod);
    }
    printf("%d\n", ans);
    return 0;
}