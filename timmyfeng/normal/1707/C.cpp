#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, L = __lg(N) + 1;

vector<pair<int, int>> bad_edges;
vector<int> adj[N];
int in[N], out[N], tour[N];
int parent[L][N];

void dfs(int u, int p = -1) {
    static int t = 0;
    tour[t] = u;
    in[u] = t++;
    for (auto c : adj[u]) {
        if (c != p) {
            parent[0][c] = u;
            dfs(c, u);
        }
    }
    out[u] = t;
}

bool is_ancestor(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int descend(int u, int v) {
    for (int i = L - 1; i >= 0; --i) {
        if (!is_ancestor(parent[i][v], u))
            v = parent[i][v];
    }
    return v;
}

int euler_sum[N];

void update(int u, int k) {
    euler_sum[in[u]] += k;
    euler_sum[out[u]] -= k;
}

int dsu[N];

int find(int u) {
    return dsu[u] == u ? u : dsu[u] = find(dsu[u]);
}

bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    dsu[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    iota(dsu, dsu + n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        if (unite(u, v)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            bad_edges.push_back({u, v});
        }
    }

    dfs(0);

    for (int i = 1; i < L; ++i) {
        for (int j = 0; j < n; ++j) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }

    for (auto [u, v] : bad_edges) {
        if (is_ancestor(u, v)) {
            update(0, 1);
            update(descend(u, v), -1);
            update(v, 1);
        } else if (is_ancestor(v, u)) {
            update(0, 1);
            update(descend(v, u), -1);
            update(u, 1);
        } else {
            update(u, 1);
            update(v, 1);
        }
    }

    for (int i = 0; i <= n; ++i) {
        if (i) euler_sum[i] += euler_sum[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        cout << (euler_sum[in[i]] == m - n + 1);
    }

    cout << "\n";
}