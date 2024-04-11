#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

vector<array<int, 2>> adj[N];
int visited[N];

void dfs_nodes(int u, vector<int> &v) {
    visited[u] = 1;
    for (auto [c, t] : adj[u]) {
        if (visited[c] == 0) {
            dfs_nodes(c, v);
        }
    }
    v.push_back(u);
}

bool dfs_cycle(int u) {
    visited[u] = 2;
    bool cycle = false;
    for (auto [c, t] : adj[u]) {
        if (t == 0) {
            if (visited[c] == 1) {
                cycle |= dfs_cycle(c);
            } else if (visited[c] == 2) {
                cycle = true;
            }
        }
    }
    visited[u] = 3;
    return cycle;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }

    int ans = n;
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0) {
            vector<int> nodes;
            dfs_nodes(i, nodes);

            bool cycle = false;
            for (auto j : nodes) {
                if (visited[j] == 1) {
                    cycle |= dfs_cycle(j);
                }
            }

            if (!cycle) {
                --ans;
            }
        }
    }

    cout << ans << "\n";
}