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

const int MAXN = 3300, mod = 998244353;

int n, m, a[MAXN][MAXN], top;

struct edge { int u, v, w; bool operator < (const edge &tmp) const { return w < tmp.w; } } e[MAXN * MAXN];
vector <int> E[MAXN];

namespace dsu {
    int fa[MAXN];
    inline int gf (int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }
}

int fa[MAXN], dep[MAXN], siz[MAXN], wson[MAXN], tp[MAXN];
void dfs1 (int x, int f) {
    fa[x] = f, dep[x] = dep[f] + 1, siz[x] = 1;
    for (auto v: E[x]) dfs1(v, x), siz[x] += siz[v], wson[x] = siz[wson[x]] > siz[v] ? wson[x] : v;
}
void dfs2 (int x) {
    if (wson[x]) tp[wson[x]] = tp[x], dfs2(wson[x]);
    for (auto v: E[x]) if (v != wson[x]) tp[v] = v, dfs2(v);
}
int lca (int u, int v) {
    while (tp[u] != tp[v]) {
        if (dep[tp[u]] < dep[tp[v]]) swap(u, v);
        u = fa[tp[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

int w[MAXN], mx[MAXN];
int f[MAXN][MAXN], tmp[MAXN];

bool judge (int x) {
    int now = mx[x];
    x = fa[x]; while (x) { if (w[x] < now) return 0; x = fa[x]; }
    return 1;
}
void solve (int x) {
    siz[x] = 1; mx[x] = max(mx[x], w[x]);
    if (!E[x].empty()) f[x][0] = 1;
    for (auto v: E[x]) {
        solve(v); mx[x] = max(mx[x], mx[v]);
        for (int i = 0; i <= siz[x] + siz[v]; i++) tmp[i] = 0;
        for (int i = 0; i <= siz[x]; i++) for (int j = 0; j <= siz[v]; j++)
            tmp[i + j] = (tmp[i + j] + 1ll * f[x][i] * f[v][j]) % mod;
        siz[x] += siz[v];
        for (int i = 0; i <= siz[x]; i++) f[x][i] = tmp[i];
    }
    if (judge(x)) f[x][1] = (f[x][1] + 1) % mod;
}

int main () {
    n = top = read(); int i, j;
    for (i = 1; i <= (n << 1); i++) dsu::fa[i] = i;
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) a[i][j] = read();
    for (i = 1; i <= n; i++) for (j = i + 1; j <= n; j++) ++m, e[m].u = i, e[m].v = j, e[m].w = a[i][j];
    sort(e + 1, e + m + 1);
    for (i = 1; i <= m; i++) {
        int u = dsu::gf(e[i].u), v = dsu::gf(e[i].v);
        if (u == v) continue;
        dsu::fa[u] = dsu::fa[v] = ++top;
        E[top].push_back(u); E[top].push_back(v);
        w[top] = e[i].w; e[i].w = -1;
    }
    dfs1(top, 0); tp[top] = top; dfs2(top);
    for (i = 1; i <= m; i++) if (e[i].w != -1) {
        int x = lca(e[i].u, e[i].v);
        mx[x] = max(mx[x], e[i].w);
    }
    solve(top);
    for (i = 1; i <= n; i++) printf("%d ", (f[top][i] + mod) % mod);
    puts("");
    return 0;
}