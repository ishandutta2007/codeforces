#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int u[maxn], v[maxn], w[maxn], uf[maxn];
int fa[maxn][20], fe[maxn][20], dep[maxn];
int fr[maxn], to[maxn], sz[maxn], dfn[maxn];
bool select[maxn];
vector<pair<int, int>> g[maxn];

int find(int x) {
    if (x == uf[x]) return x;
    return uf[x] = find(uf[x]);
}

void merge(int x, int y) {
    uf[find(x)] = find(y);
}

void dfs(int x, int p, int e) {
    dep[x] = ~p ? dep[p] + 1 : 0;  
    fa[x][0] = p;
    fe[x][0] = e;
    for (int i = 1; (1 << i) <= dep[x]; ++i) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
        fe[x][i] = max(fe[x][i - 1], fe[fa[x][i - 1]][i - 1]);
    }
    
    sz[x] = 1;
    to[x] = -1;

    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i].first, w = g[x][i].second;
        if (u == p) continue;
        dfs(u, x, w);
        sz[x] += sz[u];
        if (to[x] == -1 || sz[u] > sz[to[x]]) to[x] = u;
    }
}

int query(int u, int v) {
    int res = 0;
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 0; i < 20; ++i) {
        if ((dep[v] - dep[u]) >> i & 1) {
            res = max(res, fe[v][i]);
            v = fa[v][i];
        }
    }
    if (u == v) return res;

    for (int i = 19; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            res = max(res, fe[u][i]);
            res = max(res, fe[v][i]);
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    res = max(res, fe[u][0]);
    res = max(res, fe[v][0]);
    return res;
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 0; i < 20; ++i) {
        if ((dep[v] - dep[u]) >> i & 1)
            v = fa[v][i];
    }
    if (u == v) return u;

    for (int i = 19; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

void link(int x, int f) {
    static int tk = 0;
    fr[x] = f;
    dfn[x] = tk++;

    if (~to[x]) link(to[x], f);

    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i].first;
        if (u == fa[x][0] || u == to[x]) continue;
        link(u, u);
    }
}

namespace sgt {
    int tg[maxn * 4];

    void init() {
        fill(tg, tg + maxn * 4, 1000000000);
    }

    void modify(int l, int r, int ql, int qr, int v, int o = 0) {
        if (l >= qr || ql >= r) return;
        if (l >= ql && r <= qr) {
            tg[o] = min(tg[o], v);
            return;
        }

        modify(l, (l + r) >> 1, ql, qr, v, o * 2 + 1);
        modify((l + r) >> 1, r, ql, qr, v, o * 2 + 2);
    }

    int query(int l, int r, int p, int o = 0) {
        if (r - l == 1)
            return tg[o];

        int res = tg[o];
        if (p < ((l + r) >> 1))
            res = min(res, query(l, (l + r) >> 1, p, o * 2 + 1));
        else
            res = min(res, query((l + r) >> 1, r, p, o * 2 + 2));
        return res;
    }
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        --u[i], --v[i];
    }

    vector<int> ed(m);
    iota(ed.begin(), ed.end(), 0);
    sort(ed.begin(), ed.end(), [&](int i, int j) {
        return w[i] < w[j];      
    });

    for (int i = 0; i < n; ++i) uf[i] = i;

    for (int i = 0; i < m; ++i) {
        int j = ed[i];
        if (find(u[j]) != find(v[j])) {
            select[j] = true;
            merge(u[j], v[j]);
            g[u[j]].emplace_back(v[j], w[j]);
            g[v[j]].emplace_back(u[j], w[j]);
        }
    }
    
    dfs(0, -1, -1);
    link(0, 0);

    sgt::init();

    for (int i = 0; i < m; ++i) {
        if (!select[i]) {
            int x = u[i], y = v[i];
            int fx = fr[x], fy = fr[y];
            while (fx != fy) {
                if (dep[fx] < dep[fy]) {
                    swap(fx, fy);
                    swap(x, y);
                }
                sgt::modify(0, n, dfn[fx], dfn[x] + 1, w[i]);
                x = fa[fx][0];
                fx = fr[x];
            }
            if (dfn[x] > dfn[y]) swap(x, y);
            if (dfn[x] < dfn[y]) sgt::modify(0, n, dfn[x] + 1, dfn[y] + 1, w[i]);
        }
    }

    for (int i = 0; i < m; ++i) {
        if (!select[i]) {
            printf("%d\n", query(u[i], v[i]));
        } else {
            if (dep[u[i]] < dep[v[i]]) swap(u[i], v[i]);
            printf("%d\n", sgt::query(0, n, dfn[u[i]]));
        }
    }
    return 0;
}