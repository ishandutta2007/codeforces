#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;
const int W = 50 + 1;

vector<array<int, 2>> adj[N];
int dist[N][W];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < W; ++j) {
            dist[i][j] = INT_MAX;
        }
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> que;
    que.push({0, 1, 0});
    dist[1][0] = 0;

    while (!que.empty()) {
        auto [d, u, v] = que.top();
        que.pop();
        if (d > dist[u][v]) {
            continue;
        }

        for (auto [c, w] : adj[u]) {
            int new_d = d + (v == 0 ? 0 : (v + w) * (v + w));
            int new_v = (v == 0 ? w : 0);
            if (new_d < dist[c][new_v]) {
                dist[c][new_v] = new_d;
                que.push({new_d, c, new_v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << (dist[i][0] == INT_MAX ? -1 : dist[i][0]) << " ";
    }
    cout << "\n";
}