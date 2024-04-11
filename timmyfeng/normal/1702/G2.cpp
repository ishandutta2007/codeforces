#include <bits/stdc++.h>
using namespace std;

const int N = 2e5, L = __lg(N) + 1;

int parent[L][N], in[N], out[N], n;
vector<int> adj[N];

void dfs(int u) {
    static int t = 0;
    in[u] = ++t;
    for (auto c : adj[u]) {
        if (parent[0][u] == c) continue;
        parent[0][c] = u;
        dfs(c);
    }
    out[u] = t;
}

bool is_ancestor(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    }

    for (int j = __lg(n); j >= 0; --j) {
        if (!is_ancestor(parent[j][u], v)) {
            u = parent[j][u];
        }
    }

    return parent[0][u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    for (int i = 1; i <= __lg(n); ++i) {
        for (int j = 0; j < n; ++j) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }

    int q; cin >> q;

    while (q--) {
        int k; cin >> k;

        vector<int> p(k);
        for (auto &i : p) cin >> i, --i;

        sort(p.begin(), p.end(), [&](int a, int b) {
            return in[a] < in[b];
        });

        int root = p[0];
        for (int i = 1; i < k; ++i) {
            root = lca(root, p[i]);
        }

        if (p[0] == root) {
            p.erase(p.begin());
            --k;
        }

        bool ok = true;
        int breaks = 0;
        for (int i = 1; i < k; ++i) {
            if (!is_ancestor(p[i - 1], p[i])) {
                ok &= (lca(p[i - 1], p[i]) == root);
                ++breaks;
            }
        }

        cout << (ok && breaks <= 1 ? "YES" : "NO") << "\n";
    }
}