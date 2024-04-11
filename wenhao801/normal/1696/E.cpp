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
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 400400, mod = 1e9 + 7;
union mint {
    int x;
    mint () { x = 0; }
    mint (int _x) { x = _x % mod; if (x < 0) x += mod; }
    mint operator + (const mint &t) const { return mint{x + t.x >= mod ? (x + t.x - mod) : (x + t.x)}; }
    mint operator - (const mint &t) const { return mint{x < t.x ? (x - t.x + mod) : (x - t.x)}; }
    mint operator * (const mint &t) const { return mint{1ll * x * t.x % mod}; }
    mint operator -() const { return x ? (mod - x) : x; }
    void operator += (const mint &t) { x += t.x; if (x >= mod) x -= mod; }
    void operator -= (const mint &t) { x -= t.x; if (x < 0) x += mod; }
    void operator *= (const mint &t) { x = 1ll * x * t.x % mod; }
    bool operator == (const mint &t) const { return x == t.x; }
    bool operator != (const mint &t) const { return x != t.x; }
    explicit operator int() const { return x; }
};
mint qpow (mint x, int y) { mint ret = 1; for (; y; x *= x, y >>= 1) if (y & 1) ret *= x; return ret; }
mint inv (mint x) { return qpow(x, mod - 2); }

mint fac[MAXN], ifac[MAXN];
mint binom(int x, int y) { if (x < y || y < 0) return 0; return fac[x] * ifac[y] * ifac[x - y]; }
int n, a[MAXN], b[MAXN];

int main () {
    n = read() + 1; int i, j;
    fac[0] = ifac[0] = 1;
    for (i = 1; i < MAXN; i++) fac[i] = fac[i - 1] * i;
    ifac[MAXN - 1] = inv(fac[MAXN - 1]);
    for (i = MAXN - 2; i >= 1; i--) ifac[i] = ifac[i + 1] * (i + 1);
    for (i = 1; i <= n; i++) a[i] = read(), ++b[a[i]];
    if (!a[1]) { puts("0"); return 0; }
    for (i = MAXN - 2; i >= 0; i--) b[i] += b[i + 1];
    mint ans = 0;
    for (i = 1; i <= n; i++) ans += binom(i - 1 + a[i] - 1, i - 1);
    for (i = 1; i < MAXN; i++) ans += binom(i - 1 + b[i] - 1, i - 1);
    printf("%d\n", ans - 1);
    return 0;
}