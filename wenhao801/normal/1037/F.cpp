#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int mod = 1e9 + 7;
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

const int MAXN = 1001000;
int n, K, a[MAXN];

bool cmp(int u, int v) { return a[u] != a[v] ? (a[u] > a[v]) : (u < v); }
int pre[MAXN];
int p[MAXN], q[MAXN];

set <int> s;
mint foo(int tlim) { return mint((1ll * tlim * (tlim + 1) / 2) % mod) * (K - 1); }

int main() {
    n = read(), K = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read(), pre[i] = i;
    sort(pre + 1, pre + n + 1, cmp);
    s.insert(0), s.insert(n + 1);
    for (i = 1; i <= n; i++) {
        int x = pre[i]; auto it = s.lower_bound(x);
        q[x] = *it - x - 1;
        --it; p[x] = x - *it - 1;
        s.insert(x);
    }
    mint ans = 0;
    for (i = 1; i <= n; i++) {
        int p = ::p[i], q = ::q[i];
        int lim = (p + q) / (K - 1);
        mint tmp = lim;
        tmp -= foo(lim);
        tmp += foo(p / (K - 1)) + mint(lim - p / (K - 1)) * p;
        tmp += foo(q / (K - 1)) + mint(lim - q / (K - 1)) * q;
        ans += tmp * a[i];
    }
    printf("%d\n", ans);
    return 0;
}