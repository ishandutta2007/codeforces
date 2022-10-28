#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 1;

int dist[N], visited[N], diameter[N];
vector<int> adj[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        fill(dist, dist + n + 1, -1);
        dist[i] = 0;

        queue<int> que;
        que.push(i);

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            if (visited[u] == 0) {
                visited[u] = i;
            }

            diameter[visited[u]] = max(diameter[visited[u]], dist[u]);

            for (auto c : adj[u]) {
                if (dist[c] == -1) {
                    dist[c] = dist[u] + 1;
                    que.push(c);
                } else if (dist[c] % 2 == dist[u] % 2) {
                    cout << -1 << "\n";
                    exit(0);
                }
            }
        }
    }

    cout << accumulate(diameter, diameter + n + 1, 0) << "\n";
}