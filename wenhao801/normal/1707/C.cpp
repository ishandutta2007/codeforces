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

const int MAXN = 202000;
using pii = pair <int, int>;
#define fr first
#define se second

vector <int> E[MAXN];

namespace dsu {
    int fa[MAXN];
    int gf(int x) { return fa[x] == x ? x : (fa[x] = gf(fa[x])); }
}
int n, m; pii e[MAXN]; bool sp[MAXN];

int dep[MAXN], fa[MAXN][22], siz[MAXN], dfn[MAXN], cnt;
void dfs(int x, int f) {
    fa[x][0] = f; dep[x] = dep[f] + 1;
    siz[x] = 1, dfn[x] = ++cnt;
    for (int i = 1; i < 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (auto i: E[x]) if (i != f) dfs(i, x), siz[x] += siz[i];
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 20; i >= 0; i--) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (int i = 20; i >= 0; i--) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int s[MAXN];

int main() {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) dsu::fa[i] = i;
    for (i = 1; i <= m; i++) {
        e[i].fr = read(), e[i].se = read();
        if (dsu::gf(e[i].fr) != dsu::gf(e[i].se))
            E[e[i].fr].push_back(e[i].se), E[e[i].se].push_back(e[i].fr),
            dsu::fa[dsu::gf(e[i].fr)] = dsu::gf(e[i].se);
        else sp[i] = 1;
    }
    dfs(1, 0);
    for (i = 1; i <= m; i++) if (sp[i]) {
        int u = e[i].fr, v = e[i].se, L = lca(u, v);
        if (L == v) swap(u, v);
        if (L == u) {
            int tmp = v;
            for (int j = 20; j >= 0; j--) if (dep[fa[tmp][j]] > dep[u]) tmp = fa[tmp][j];
            ++s[dfn[tmp]], --s[dfn[tmp] + siz[tmp]], --s[dfn[v]], ++s[dfn[v] + siz[v]];
        }
        else ++s[1], --s[dfn[u]], --s[dfn[v]], ++s[dfn[u] + siz[u]], ++s[dfn[v] + siz[v]];
    }
    for (i = 1; i <= n; i++) s[i] += s[i - 1];
    for (i = 1; i <= n; i++) printf("%d", !bool(s[dfn[i]]));
    putchar('\n');
    return 0;
}