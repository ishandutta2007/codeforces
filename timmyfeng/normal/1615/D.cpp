#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 200000;

vector<pair<int, int>> adj[N];
array<int, 3> edges[N];
int node_parity[N];

bool dfs(int u) {
    for (auto [c, w] : adj[u]) {
        if (node_parity[c] == -1) {
            node_parity[c] = node_parity[u] ^ w;
            if (!dfs(c)) return false;
        }
        if (node_parity[c] != (node_parity[u] ^ w)) { return false; }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        fill(adj + 1, adj + n + 1, vector<pair<int, int>>());

        for (int i = 0; i < n + m - 1; ++i) {
            auto &[u, v, w] = edges[i];
            cin >> u >> v >> w;

            if (w != -1) {
                int parity = popcount((unsigned) w) % 2;
                adj[u].push_back({v, parity});
                adj[v].push_back({u, parity});
            }
        }

        bool consistent = true;
        fill(node_parity + 1, node_parity + n + 1, -1);
        for (int i = 1; i <= n; ++i) {
            if (node_parity[i] == -1) {
                node_parity[i] = 0;
                consistent &= dfs(i);
            }
        }

        if (!consistent) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n - 1; ++i) {
                auto &[u, v, w] = edges[i];
                if (w == -1) w = node_parity[u] ^ node_parity[v];
                cout << u << " " << v << " " << w << "\n";
            }
        }
    }
}