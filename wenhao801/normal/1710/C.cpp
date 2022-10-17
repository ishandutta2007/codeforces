#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;
const int MAXN = 200200, mod = 998244353;
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

char str[MAXN]; bool a[MAXN]; int n;
mint f[MAXN][2][2][2][2][2];

int main() {
    scanf("%s", str); n = strlen(str); int i, j;
    for (i = 0; i < n; i++) a[i] = str[n - i - 1] == '1';
    f[n][1][1][1][1][1] = 1;
    for (i = n; i >= 1; i--) {
        for (int x = 0; x <= 1; x++) for (int z = 0; z <= 1; z++)
            for (int p = 0; p <= 1; p++) for (int q = 0; q <= 1; q++) for (int r = 0; r <= 1; r++) {
                const mint val = f[i][x][z][p][q][r];
                if (!val.x) continue;
                for (int A = 0; A <= (x ? a[i - 1] : 1); A++) for (int C = 0; C <= (z ? a[i - 1] : 1); C++) for (int B = 0; B <= 1; B++) {
                    if (!((A ^ B) & (A ^ C)) && !(r && B && !C)) {
                        f[i - 1][x && a[i - 1] == A][z && a[i - 1] == C][p && A == B][q && A == C][r && B == C] += val;
                    }
                }
            }
    }
    mint ans = 0;
    for (i = 0; i <= 1; i++) for (j = 0; j <= 1; j++) ans += f[0][i][j][0][0][0];
    ans *= 6;

    mint N = 0;
    for (i = 0; i < n; i++) N += qpow(2, i) * a[i];
    ans = N * N * N - N - ans;

    printf("%d\n", ans);
    return 0;
}