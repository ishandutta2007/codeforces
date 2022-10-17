#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

const int mod = 998244353, MAXN = 2002000;
union mint {
    int x;
    mint () { x = 0; }
    mint (int _x) { x = _x % mod; if (x < 0) x += mod; }
    void operator += (const mint &t) { x += t.x; if (x >= mod) x -= mod; }
    void operator -= (const mint &t) { x -= t.x; if (x < 0) x += mod; }
    void operator *= (const mint &t) { x = 1ll * x * t.x % mod; }
    bool operator == (const mint &t) const { return x == t.x; }
    bool operator != (const mint &t) const { return x != t.x; }
    mint operator + (const mint &t) const { mint tmp = *this; tmp += t; return tmp; }
    mint operator - (const mint &t) const { mint tmp = *this; tmp -= t; return tmp; }
    mint operator * (const mint &t) const { mint tmp = *this; tmp *= t; return tmp; }
    mint operator -() const { return x ? (mod - x) : x; }
    explicit operator int() const { return x; }
};
ostream & operator << (ostream &out, mint a) { return out << a.x; }
mint qpow(mint x, int y) { mint ret = 1; for (; y; x *= x, y >>= 1) if (y & 1) ret *= x; return ret; }
mint inv(mint x) { assert(x.x); return qpow(x, mod - 2); }

mint fac[MAXN], ifac[MAXN], f[MAXN];
mint binom(int x, int y) { return (x < y || y < 0) ? 0 : fac[x] * ifac[y] * ifac[x - y]; }

int n, m;
int main() {
    scanf("%d%d", &n, &m); int i, j;
    fac[0] = ifac[0] = 1;
    for (i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
    ifac[n] = inv(fac[n]); for (i = n - 1; i >= 1; i--) ifac[i] = ifac[i + 1] * (i + 1);
    mint ans = 0, c = 0, tmp = inv(n + m) * m;
    for (i = 0; i <= n; i++) c += tmp * (i + 1), tmp *= i == n ? 0 : inv(n + m - i - 1) * (n - i);

    for (i = 1; i <= n; i++) ans += binom(n, i) * ((i & 1) ? 1 : -1) * (m + i) * inv(i) * c;
    printf("%d\n", ans);
    return 0;
}