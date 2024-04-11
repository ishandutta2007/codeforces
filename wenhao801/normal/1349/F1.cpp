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
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int mod = 998244353;
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
mint inv(mint x) { return qpow(x, mod - 2); }

const int MAXN = 5050;
int n; mint f[MAXN][MAXN], fac[MAXN], ifac[MAXN], ans[MAXN];
mint binom(int x, int y) { if (x < y || y < 0) return 0; return fac[x] * ifac[y] * ifac[x - y]; }

int main() {
    n = read(); int i, j;
    fac[0] = ifac[0] = 1;
    for (i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
    ifac[n] = inv(fac[n]); for (i = n - 1; i >= 1; i--) ifac[i] = ifac[i + 1] * (i + 1);

    f[0][0] = 1;
    for (i = 1; i <= n; i++) for (j = 1; j <= i; j++)
        f[i][j] = f[i - 1][j] * j + f[i - 1][j - 1] * (i - j + 1);
    for (i = 1; i <= n; i++) for (j = 1; j <= i; j++) ans[j] += f[i][j] * binom(n, i) * fac[n - i];
    for (i = 1; i <= n; i++) printf("%d ", ans[i]); putchar('\n');
    return 0;
}