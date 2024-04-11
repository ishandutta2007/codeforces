#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> g(n);
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
    edges.emplace_back(u, v);
  }
  vector<vector<int>> dist(n, vector<int>(n, 1e9));
  for (int i = 0; i < n; i++) {
    dist[i][i] = 0;
    set<pair<int, int>> que;
    que.insert({0, i});
    while (!que.empty()) {
      auto it = que.begin();
      int d = it -> first;
      int x = it -> second;
      que.erase(it);
      if (d > dist[i][x]) {
        continue;
      }
      for (auto e : g[x]) {
        int y = e.first;
        int w = e.second;
        if (dist[i][y] > dist[i][x] + w) {
          dist[i][y] = dist[i][x] + w;
          que.insert({dist[i][y], y});
        }
      }
    }
  }
  vector<int> a(k), b(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }
  long long ans = 1e18;
  for (int i = 0; i < edges.size(); i++) {
    int x = edges[i].first;
    int y = edges[i].second;
    long long curr = 0;
    for (int j = 0; j < k; j++) {
      curr += min({dist[a[j]][b[j]], dist[a[j]][x] + dist[y][b[j]], dist[a[j]][y] + dist[x][b[j]]});
    }
    ans = min(ans, curr);
  }
  cout << ans << '\n';
  return 0;
}