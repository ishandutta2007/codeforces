#include <bits/stdc++.h>
using namespace std;

const int N = 601;

long long adj[N][N], dist[N][N], length[N][N];
bool useful[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = w;
    }

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        long long l;
        cin >> u >> v >> l;
        length[u][v] = length[v][u] = l;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                dist[i][j] = adj[i][j] == 0 ? LLONG_MAX : adj[i][j];
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long maxi = 0;
            for (int k = 1; k <= n; ++k) {
                maxi = max(maxi, length[k][j] - dist[k][i]);
            }

            for (int k = 1; k <= n; ++k) {
                useful[i][k] |= adj[i][k] > 0 && maxi - dist[k][j] >= adj[i][k];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            ans += useful[i][j];
        }
    }

    cout << ans << "\n";
}