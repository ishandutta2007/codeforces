#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    g[v].emplace_back(u, w);
  }
  vector<vector<int>> dist(n, vector<int>(2, 1e9));
  dist[n - 1][0] = dist[n - 1][1] = 0;
  set<pair<int, int>> que;
  que.insert({0, n - 1});
  while (!que.empty()) {
    auto it = que.begin();
    int d = it -> first;
    int x = it -> second;
    que.erase(it);
    for (auto e : g[x]) {
      int y = e.first;
      int w = e.second;
      if (dist[y][w] > d + 1) {
        if (dist[y][w] != 1e9) {
          que.erase(que.find({max(dist[y][w], dist[y][w ^ 1]), y}));
        }
        dist[y][w] = d + 1;
        que.insert({max(dist[y][w], dist[y][w ^ 1]), y});
      }
    }
  }
  int ans = max(dist[0][0], dist[0][1]);
  cout << (ans == 1e9 ? -1 : ans) << '\n';
  for (int i = 0; i < n; i++) {
    cout << (dist[i][0] > dist[i][1] ? 0 : 1);
  }
  cout << '\n';
  return 0;
}