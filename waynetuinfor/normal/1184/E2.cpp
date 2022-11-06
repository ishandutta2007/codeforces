#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
vector<pair<int, int>> g[maxn];
vector<pair<int, int>> mst[maxn];
int uf[maxn], fa[maxn][20], fe[maxn][20];
int dep[maxn], u[maxn], v[maxn], w[maxn];
bool select[maxn];

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

    for (int i = 0; i < (int)mst[x].size(); ++i) {
        int u = mst[x][i].first, w = mst[x][i].second;
        if (u == p) continue;
        dfs(u, x, w);
    }
}

int query(int u, int v) {
    int res = 0;
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 0; i < 20; ++i) {
        if ((dep[v] - dep[u]) >> i & 1) {
            // printf("fe[%d][%d] = %d\n", v, i, fe[v][i]);
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

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        --u[i], --v[i];
        g[u[i]].emplace_back(v[i], w[i]);
        g[v[i]].emplace_back(u[i], w[i]);
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
            mst[u[j]].emplace_back(v[j], w[j]);
            mst[v[j]].emplace_back(u[j], w[j]);
        }
    }

    dfs(0, -1, -1);

    for (int i = 0; i < m; ++i) {
        if (select[i]) continue;
        printf("%d\n", query(u[i], v[i]));
    }
    return 0;
}