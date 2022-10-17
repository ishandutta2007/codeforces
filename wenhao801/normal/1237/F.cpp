#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>

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
mint inv(mint x) { assert(x.x); return qpow(x, mod - 2); }

const int MAXN = 4040;
int n, m, K; bool visR[MAXN], visC[MAXN];

using vim = vector <mint>;
#define size(v) (int(v.size()))

vim f[MAXN], A, B;
vim mul(vim p, vim q) {
    vim res(size(p) + size(q) - 1);
    for (int i = 0; i < size(p); i++) for (int j = 0; j < size(q); j++)
        res[i + j] += p[i] * q[j];
    return res;
}

mint fac[100100], ifac[100100];
mint binom(int x, int y) { if (x < y || y < 0) return 0; return fac[x] * ifac[y] * ifac[x - y]; }

mint s[MAXN][MAXN];

int main() {
    n = read(), m = read(), K = read() * 2; int i, j;
    while (K--) {
        int x = read(), y = read();
        visR[x] = visC[y] = 1;
    }
    
    fac[0] = ifac[0] = 1; const int lim = 1e5;
    for (i = 1; i <= lim; i++) fac[i] = fac[i - 1] * i;
    ifac[lim] = inv(fac[lim]); for (i = lim - 1; i >= 1; i--) ifac[i] = ifac[i + 1] * (i + 1);

    for (i = 0; i < MAXN; i++) {
        f[i].resize(i + 1);
        for (j = 0; j * 2 <= i; j++) f[i][i - 2 * j] = binom(i - j, j);
    }
    A = {1}, B = {1}; int lenA = 0, lenB = 0;
    for (i = 1, j = 0; i <= n; i = max(i + 1, j)) if (!visR[i]) {
        for (j = i; j <= n && !visR[j]; j++);
        A = mul(A, f[j - i]), lenA += j - i;
    }
    for (i = 1, j = 0; i <= m; i = max(i + 1, j)) if (!visC[i]) {
        for (j = i; j <= m && !visC[j]; j++);
        B = mul(B, f[j - i]), lenB += j - i;
    }
    for (i = 0; i < size(A); i++) if ((lenA - i) % 2 == 0) {
        const int y = (lenA - i) >> 1;
        for (j = 0; j <= i; j++) s[j][y] += A[i] * binom(i, j);
    }
    mint ans = 0;
    for (i = 0; i < size(B); i++) if ((lenB - i) % 2 == 0) {
        const int y = (lenB - i) >> 1;
        for (j = 0; j <= i; j++) ans += B[i] * binom(i, j) * s[y][j] * fac[y] * fac[j];
    }
    printf("%d\n", ans);
    return 0;
}