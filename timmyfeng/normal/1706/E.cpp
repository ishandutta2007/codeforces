#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, L = __lg(N) + 1;

int in[N], out[N], depth[N], parent[N], id[N];
vector<int> adj[N];

void dfs(int u) {
    static int t = 0;
    in[u] = t++;
    for (auto c : adj[u]) {
        depth[c] = depth[u] + 1;
        dfs(c);
    }
    out[u] = t;
}

bool is_ancestor(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int dsu[N];

int find(int u) {
    return dsu[u] == u ? u : dsu[u] = find(dsu[u]);
}

pair<int, int> sparse[L][N];
int jump[L][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m, q; cin >> n >> m >> q;

        fill(adj, adj + 2 * n - 1, vector<int>());
        iota(parent, parent + 2 * n - 1, 0);
        iota(dsu, dsu + 2 * n - 1, 0);

        int ptr = n;
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v; --u, --v;
            u = find(u), v = find(v);
            if (u != v) {
                parent[u] = parent[v] = ptr;
                dsu[u] = dsu[v] = ptr;
                adj[ptr].push_back(u);
                adj[ptr].push_back(v);
                id[ptr] = i + 1;
                ++ptr;
            }
        }

        for (int i = 0; i <= __lg(2 * n - 1); ++i) {
            for (int j = 0; j < 2 * n - 1; ++j) {
                if (i == 0) {
                    jump[0][j] = parent[j];
                } else {
                    jump[i][j] = jump[i - 1][jump[i - 1][j]];
                }
            }
        }

        dfs(2 * n - 2);

        for (int i = 0; i < n - 1; ++i) {
            int j = i + 1;
            for (int k = __lg(2 * n - 1); k >= 0; --k) {
                if (!is_ancestor(jump[k][j], i)) {
                    j = jump[k][j];
                }
            }
            j = parent[j];
            sparse[0][i] = {depth[j], j};
        }

        for (int i = 1; i <= __lg(n - 1); ++i) {
            for (int j = 0; j + (1 << i) <= n - 1; ++j) {
                sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
            }
        }

        while (q--) {
            int l, r; cin >> l >> r; --l, --r;
            if (l == r) {
                cout << 0 << "\n";
                continue;
            }
            int lg = __lg(r - l);
            auto result = min(sparse[lg][l], sparse[lg][r - (1 << lg)]);
            cout << id[result.second] << "\n";
        }
    }
}