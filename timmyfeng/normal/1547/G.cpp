#include <bits/stdc++.h>
using namespace std;

const int N = 400000;

vector<int> adj[N], cycle_nodes, paths_nodes;
bool cycle[N], paths[N];
int visited[N];

void dfs_span(int u) {
    visited[u] = 1;
    for (auto c : adj[u]) {
        if (visited[c] == 0) {
            dfs_span(c);
        } else if (visited[c] == 1) {
            cycle_nodes.push_back(c);
        } else {
            paths_nodes.push_back(c);
        }
    }
    visited[u] = 2;
}

void dfs_cycle(int u) {
    cycle[u] = true;
    for (auto c : adj[u]) {
        if (!cycle[c]) {
            dfs_cycle(c);
        }
    }
}

void dfs_paths(int u) {
    paths[u] = true;
    for (auto c : adj[u]) {
        if (!paths[c]) {
            dfs_paths(c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        fill(adj, adj + n, vector<int>());
        fill(paths, paths + n, false);
        fill(cycle, cycle + n, false);
        fill(visited, visited + n, 0);
        paths_nodes.clear();
        cycle_nodes.clear();

        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
        }

        dfs_span(0);

        for (auto i : cycle_nodes) {
            if (!cycle[i]) {
                dfs_cycle(i);
            }
        }

        for (auto i : paths_nodes) {
            if (!paths[i]) {
                dfs_paths(i);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                cout << 0 << " ";
            } else if (cycle[i]) {
                cout << -1 << " ";
            } else if (paths[i]) {
                cout << 2 << " ";
            } else {
                cout << 1 << " ";
            }
        }
        cout << "\n";
    }
}