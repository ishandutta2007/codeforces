#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;
const int L = __lg(N) + 1;

int color[N], in[N], out[N], low[N], t, k;
vector<array<int, 2>> adj[N];
vector<int> bcc[N];
bool visited[N];

void dfs_color(int u, int x) {
    color[u] = x;
    for (auto [c, i] : adj[u]) {
        if (in[c] > in[u]) {
            if (color[c] == 0) {
                dfs_color(c, x);
            } else if (color[c] != x) {
                bcc[x].push_back(color[c]);
                bcc[color[c]].push_back(x);
            }
        }
    }
}

void dfs_bcc(int u) {
    in[u] = low[u] = ++t;
    for (auto [c, i] : adj[u]) {
        if (!visited[i]) {
            visited[i] = true;
            if (in[c] > 0) {
                low[u] = min(low[u], in[c]);
            } else {
                dfs_bcc(c);
                low[u] = min(low[u], low[c]);
            }
        }
    }

    if (low[u] == in[u]) {
        dfs_color(u, ++k);
    }
}

int par[L][N];

void dfs_lca(int u) {
    in[u] = ++t;
    for (auto c : bcc[u]) {
        if (par[0][u] != c) {
            par[0][c] = u;
            dfs_lca(c);
        }
    }
    out[u] = t;
}

int up[N], down[N];

void dfs_sum(int u) {
    for (auto c : bcc[u]) {
        if (par[0][u] != c) {
            dfs_sum(c);
            up[u] += up[c];
            down[u] += down[c];
        }
    }

    if (up[u] > 0 && down[u] > 0) {
        cout << "No\n";
        exit(0);
    }
}

bool ancestor(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v) {
    if (ancestor(u, v)) {
        return u;
    }

    for (int i = __lg(k); i >= 0; --i) {
        if (!ancestor(par[i][u], v)) {
            u = par[i][u];
        }
    }
    return par[0][u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            dfs_bcc(i);
        }
    }

    t = 0;
    for (int i = 1; i <= k; ++i) {
        if (par[0][i] == 0) {
            dfs_lca(i);
        }
    }
    out[0] = t;

    for (int i = 1; i <= __lg(k); ++i) {
        for (int j = 1; j <= k; ++j) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    for (int i = 1; i <= q; ++i) {
        int u, v;
        cin >> u >> v;

        u = color[u], v = color[v];
        int p = lca(u, v);

        if (p == 0) {
            cout << "No\n";
            exit(0);
        }

        --up[p], --down[p];
        ++up[u], ++down[v];
    }

    for (int i = 1; i <= k; ++i) {
        if (par[0][i] == 0) {
            dfs_sum(i);
        }
    }

    cout << "Yes\n";
}