#include <bits/stdc++.h>
using namespace std;

const int N = 3000 + 1;

vector<int> adj[N];
int dist[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;

    for (int i = 1; i <= n; ++i) {
        queue<int> que;
        que.push(i);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto c : adj[u]) {
                if (c != i && dist[i][c] == 0) {
                    dist[i][c] = dist[i][u] + 1;
                    que.push(c);
                }
            }
        }
    }

    if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
        cout << -1 << "\n";
        exit(0);
    }

    int ans = dist[s1][t1] + dist[s2][t2];
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int d1 = min(dist[s1][i] + dist[j][t1], dist[s1][j] + dist[i][t1]);
            int d2 = min(dist[s2][i] + dist[j][t2], dist[s2][j] + dist[i][t2]);
            if (d1 + dist[i][j] <= l1 && d2 + dist[i][j] <= l2) {
                ans = min(ans, d1 + d2 + dist[i][j]);
            }
        }
    }

    cout << m - ans << "\n";
}