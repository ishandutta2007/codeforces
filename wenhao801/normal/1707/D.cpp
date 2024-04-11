#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>
#include <ctime>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int n = read(), mod = read();
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

const int MAXN = 2020;
vector <int> E[MAXN];

mint h[MAXN][MAXN], sh[MAXN][MAXN];

mint sav[MAXN], tp[MAXN][MAXN], ts[MAXN][MAXN];
void dfs(int x, int fa) {
    if (E[x][0] == fa && E[x].size() == 1) {
        for (int i = 1; i <= n; i++) h[x][i] = 1;
        return;
    }
    int i, j;
    for (i = 0; i < E[x].size(); i++) if (E[x][i] == fa) { swap(E[x][i], E[x][0]); break; }
    for (auto v: E[x]) if (v != fa) dfs(v, x);
    for (i = 1; i <= n; i++) for (auto v: E[x]) if (v != fa) sh[v][i] = sh[v][i - 1] + h[v][i];
    if (x == 1) {
        for (i = 1; i <= n; i++) {
            h[x][i] = 1;
            for (auto v: E[x]) if (v != fa) h[x][i] *= sh[v][i];
        }
        for (i = n; i >= 1; i--) h[x][i] -= h[x][i - 1];
        return;
    }
    h[x][1] = 1;
    for (i = 1; i <= n; i++) {
        tp[0][i] = ts[E[x].size()][i] = 1;
        for (int j = 1; j < E[x].size(); j++) tp[j][i] = tp[j - 1][i] * sh[E[x][j]][i];
        for (int j = int(E[x].size()) - 1; j >= 1; j--) ts[j][i] = ts[j + 1][i] * sh[E[x][j]][i];
        for (int j = 1; j < E[x].size(); j++) if (i > 1) h[x][i] += h[E[x][j]][i] * tp[j - 1][i] * ts[j + 1][i - 1];
    }
    for (i = 1; i <= n; i++) h[x][i] += h[x][i - 1];
    for (int k = 1; k < E[x].size(); k++) {
        mint s0 = 0, s1 = 0;
        for (i = 1; i <= n; i++) {
            h[x][i] += h[E[x][k]][i] * (s0 * i - s1);
            mint tmp = tp[k - 1][i] * ts[k + 1][i];
            if (i > 1) tmp -= tp[k - 1][i - 1] * ts[k + 1][i - 1];
            s0 += tmp, s1 += tmp * i;
        }
    }
}

mint binom[MAXN][MAXN];

int main() {
    int i, j;
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
    }
    for (i = 0; i <= n; i++) {
        binom[i][0] = 1;
        for (j = 1; j <= i; j++) binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
    }
    dfs(1, 0);
    for (i = 1; i < n; i++) {
        mint ans = 0;
        for (j = 0; j < i; j++) ans += binom[i - 1][j] * h[1][i - j] * ((j & 1) ? -1 : 1);
        printf("%d ", ans);
    }
    putchar('\n');
    return 0;
}