#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<array<int, 2>>> adj(n + 1);
  while (m--) {
    int u, v, t;
    cin >> u >> v >> t;
    adj[v].push_back({u, t});
  }

  vector<int> dist(n + 1, -1);
  vector<int> ans(n + 1, -1);
  queue<int> que;
  que.push(n);
  dist[n] = 0;

  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto [c, t] : adj[u]) {
      if (ans[c] == -1) {
        ans[c] = t ^ 1;
      } else if (ans[c] == t && dist[c] == -1) {
        dist[c] = dist[u] + 1;
        que.push(c);
      }
    }
  }

  cout << dist[1] << "\n";
  for (int i = 1; i <= n; ++i) {
    cout << (ans[i] == -1 ? 0 : ans[i]);
  }
  cout << "\n";
}