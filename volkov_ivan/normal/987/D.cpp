#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, s, v, u;
    cin >> n >> m >> k >> s;
    int a[n + 1];
    vector <int> g[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < m; i++) {
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int dist[n + 1][k];
    bool visited[n + 1];
    queue <int> q;
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] == i) {
                visited[j] = 1;
                q.push(j);
                dist[j][i] = 0;
            } else {
                visited[j] = 0;
            }
        }
        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (int u : g[v]) {
                if (!visited[u]) {
                    dist[u][i] = dist[v][i] + 1;
                    visited[u] = 1;
                    q.push(u);
                }
            }
        }
    }
    int ans;
    for (int i = 1; i <= n; i++) {
        sort(dist[i], dist[i] + k);
        ans = 0;
        for (int j = 0; j < s; j++) ans += dist[i][j];
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}