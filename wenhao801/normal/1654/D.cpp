#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define pii pair <int, int>
#define fr first
#define se second

const int MAXN = 200200, mod = 998244353;
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

int cur[MAXN], mn[MAXN], n;
vector <pair <int, pii>> E[MAXN];
void add (int x, int k) {
    for (int i = 2; i * i <= x; i++) if (x % i == 0) {
        while (x % i == 0) cur[i] += k, x /= i;
        mn[i] = min(mn[i], cur[i]);
    }
    if (x != 1) cur[x] += k, mn[x] = min(mn[x], cur[x]);
}
void dfs (int x, int f) {
    for (auto i: E[x]) if (i.fr != f) {
        add(i.se.fr, 1), add(i.se.se, -1);
        dfs(i.fr, x);
        add(i.se.se, 1), add(i.se.fr, -1);
    }
}

mint ans;
void calc (int x, int f, mint k) {
    ans += k;
    for (auto i: E[x]) if (i.fr != f) calc(i.fr, x, k * i.se.fr * inv(i.se.se));
}

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j;
        for (i = 1; i < n; i++) {
            int u = read(), v = read(), p = read(), q = read();
            E[u].push_back({v, {q, p}}), E[v].push_back({u, {p, q}});
        }
        dfs(1, 0);
        ans = 0; mint now = 1;
        for (i = 1; i <= n; i++) now *= qpow(i, -mn[i]);
        calc(1, 0, now);
        printf("%d\n", ans);
        for (i = 1; i <= n; i++) cur[i] = mn[i] = 0, E[i].clear();
    }
    return 0;
}