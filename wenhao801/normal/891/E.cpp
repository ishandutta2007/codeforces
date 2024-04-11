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

const int MAXN = 5050;
int n, K, a[MAXN]; mint f[MAXN];

int main () {
    int i, j;
    cin >> n >> K;
    for (i = 1; i <= n; i++) cin >> a[i];
    f[0] = 1;
    mint ans = 1;
    for (i = 1; i <= n; i++) {
        ans *= a[i];
        for (j = i; j >= 0; j--) f[j] = f[j] * a[i] - (j ? f[j - 1] : 0);
    }
    mint tmp1 = 1, tmp2 = 1, invn = inv(n);
    for (i = 0; i <= n; i++) {
        ans -= f[i] * tmp1 * tmp2;
        tmp1 *= invn, tmp2 *= K - i;
    }
    printf("%d\n", ans);
    return 0;
}