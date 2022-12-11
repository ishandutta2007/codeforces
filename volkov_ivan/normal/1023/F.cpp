#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7, K = 20;
int up[K][N], f[K][N], tin[N], tout[N], par[N], sz[N];
vector <int> g[N];
int T = 0;

void dfs0(int v, int p = -1) {
    up[0][v] = p;
    tin[v] = T++;
    for (int i = 1; i < K; i++) {
        if (up[i - 1][v] == -1) up[i][v] = -1;
        else up[i][v] = up[i - 1][up[i - 1][v]];
    }
    for (int u : g[v]) {
        if (u != p) dfs0(u, v);
    }
    tout[v] = T - 1;
}

bool is_ancestor(int v, int u) {
    return v == -1 || (tin[v] <= tin[u] && tout[u] <= tout[v]);
}

void upd(int v, int u, int w) {
    if (is_ancestor(v, u)) return;
    for (int i = K - 1; i >= 0; i--) {
        if (is_ancestor(up[i][v], u)) continue;
        if (f[i][v] == 0) f[i][v] = w;
        v = up[i][v];
    }
    if (f[0][v] == 0) f[0][v] = w;
}

int get_par(int v) {
    if (v == par[v]) return v;
    par[v] = get_par(par[v]);
    return par[v];
}

bool merge(int v, int u) {
    v = get_par(v);
    u = get_par(u);
    if (v == u) return 0;
    if (sz[u] > sz[v]) swap(v, u);
    par[u] = v;
    sz[v] += sz[u];
    return 1;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    long long res = 0;
    vector <pair <int, int>> our;
    for (int i = 1; i <= n; i++) sz[i] = 1, par[i] = i;
    for (int i = 0; i < k; i++) {
        int v, u;
        cin >> v >> u;
        our.push_back({v, u});
        g[v].push_back(u);
        g[u].push_back(v);
        assert(merge(v, u));
    }
    vector <pair <pair <int, int>, int>> check;
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        if (merge(v, u)) {
            g[v].push_back(u);
            g[u].push_back(v);
        } else check.push_back({{v, u}, w});
    }
    dfs0(1);
    for (auto [vu, w] : check) {
        upd(vu.first, vu.second, w);
        upd(vu.second, vu.first, w);
    }
    for (int i = K - 1; i > 0; i--) {
        for (int v = 1; v <= n; v++) {
            if (f[i][v] == 0) continue;
            if (f[i - 1][v] == 0 || f[i - 1][v] > f[i][v]) f[i - 1][v] = f[i][v];
            int nxt = up[i - 1][v];
            if (f[i - 1][nxt] == 0 || f[i - 1][nxt] > f[i][v]) f[i - 1][nxt] = f[i][v];
        }
    }
    for (auto [v, u] : our) {
        if (tin[v] < tin[u]) swap(v, u);
        if (f[0][v] == 0) {
            cout << -1 << endl;
            return 0;
        }
        res += f[0][v];
    }
    cout << res << endl;
}