#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> adj[N];
int blocks[N], dist[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    while (m--) {
        int u, v; cin >> u >> v; --u, --v;
        adj[v].push_back(u);
        ++blocks[u];
    }

    priority_queue<pair<int, int>> dijkstra;
    dijkstra.push({0, n - 1});

    fill(dist, dist + n - 1, INT_MAX);

    while (!dijkstra.empty()) {
        auto [d, u] = dijkstra.top(); d = -d;
        dijkstra.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto c : adj[u]) {
            --blocks[c];
            if (d + 1 + blocks[c] < dist[c]) {
                dist[c] = d + 1 + blocks[c];
                dijkstra.push({-dist[c], c});
            }
        }
    }

    cout << dist[0] << "\n";
}