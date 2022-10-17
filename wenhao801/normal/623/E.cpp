#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;
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

const int MAXN = 1 << 18;
mint fac[MAXN], ifac[MAXN];

using ll = long long;
using LL = __uint128_t;
using uint = unsigned;

ll n, m;
namespace poly {
    const LL mod = (LL(67108863) << 64) | LL(18446744073708503041ULL);
    const uint mask = -1;
    int rev[MAXN];
    inline LL mul(LL a, LL b) {
        uint ah = (a >> 64), am = ((a >> 32) & mask), al = a & mask;
        LL fh = ah * b, fm = am * b, fl = al * b;
        LL s = (fh + ((fm + (fl >> 32)) >> 32)) >> (90 - 64);
        LL r1 = (fh << 64) + (fm << 32) + fl - s * mod;
        return r1 % mod;
    }
    void out (LL x) { if (x >= 10) out(x / 10); putchar(x % 10 + '0'); }
    LL qpow (LL x, LL y) {
        LL ret = 1;
        for (; y; y >>= 1, x = mul(x, x)) if (y & 1) ret = mul(ret, x);
        return ret;
    }
    LL inv (LL x) { return qpow(x, mod - 2); }
    
    const LL prt = 7, iprt = inv(prt);

    void FFT (LL *f, int N, bool dft) {
        int i, j, k;
        for (i = 0; i < N; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (N >> 1) : 0);
        for (i = 0; i < N; i++) if (i < rev[i]) swap(f[i], f[rev[i]]);
        for (i = 2; i <= N; i <<= 1) {
            LL nex = qpow(dft ? prt : iprt, (mod - 1) / LL(i));
            for (j = 0; j < N; j += i) {
                LL now = 1;
                for (k = j; k < j + (i >> 1); k++) {
                    LL tmp = mul(f[k + (i >> 1)], now);
                    f[k + (i >> 1)] = (f[k] - tmp + mod) % mod;
                    f[k] = (f[k] + tmp) % mod;
                    now = mul(now, nex);
                }
            }
        }
        if (!dft) { LL invN = inv(N); for (i = 0; i < N; i++) f[i] = mul(f[i], invN); }
    }

    LL tmpf[MAXN], tmpg[MAXN];
    void mul (mint *f, mint *g, int k) {
        int N = 1; while (N <= (m << 1)) N <<= 1;        
        mint tmp = 1, nex = ::qpow(2, k);
        for (int i = 0; i < N; i++, tmp *= nex) tmpf[i] = (f[i] * tmp).x, tmpg[i] = g[i].x;
        FFT(tmpf, N, 1), FFT(tmpg, N, 1);
        for (int i = 0; i < N; i++) tmpf[i] = mul(tmpf[i], tmpg[i]);
        FFT(tmpf, N, 0);
        for (int i = 0; i < N; i++) f[i] = i <= m ? (tmpf[i] % ::mod) : 0;
    }
}
mint f[MAXN], g[MAXN];

int main () {
    cin >> n >> m;
    if (n > m) { puts("0"); return 0; }
    fac[0] = ifac[0] = 1; int i, j;
    for (i = 1; i <= m; i++) fac[i] = fac[i - 1] * i;
    ifac[m] = inv(fac[m]); for (i = m - 1; i >= 1; i--) ifac[i] = ifac[i + 1] * (i + 1);
    for (i = 1; i <= m; i++) g[i] = ifac[i];
    f[0] = fac[m];
    for (i = 0; (1 << i) <= n; i++) {
        if ((n >> i) & 1) poly::mul(f, g, 1 << i);
        poly::mul(g, g, 1 << i);
    }
    mint ans = 0;
    for (i = 0; i <= m; i++) ans += f[i] * ifac[m - i];
    printf("%d\n", ans);
    return 0;
}