/**
 *    author:  tourist
 *    created: 09.09.2020 22:13:05       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    g[y].emplace_back(x, z);
  }
  const int inf = (int) 1e9;
  vector<array<int, 2>> dist(n, {inf, inf});
  dist[n - 1][0] = dist[n - 1][1] = 0;
  set<pair<int, int>> s;
  s.emplace(0, n - 1);
  while (!s.empty()) {
    int d = s.begin()->first;
    int i = s.begin()->second;
    s.erase(s.begin());
    assert(d == max(dist[i][0], dist[i][1]));
    for (auto& p : g[i]) {
      int j = p.first;
      int type = p.second;
      if (d + 1 < dist[j][type]) {
        auto it = s.find(make_pair(max(dist[j][0], dist[j][1]), j));
        if (it != s.end()) {
          s.erase(it);
        }
        dist[j][type] = d + 1;
        s.emplace(max(dist[j][0], dist[j][1]), j);
      }
    }
  }
  int d = max(dist[0][0], dist[0][1]);
  cout << (d == inf ? -1 : d) << '\n';
  for (int i = 0; i < n; i++) {
    cout << (dist[i][0] > dist[i][1] ? '0' : '1');
  }
  cout << '\n';
  return 0;
}