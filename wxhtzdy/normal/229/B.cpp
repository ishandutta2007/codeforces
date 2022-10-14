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
    --u, --v;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector<set<int>> a(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      a[i].insert(x);
    }
  }
  set<pair<long long, int>> s;
  s.insert({0LL, 0});
  const long long inf = 1e18;
  vector<long long> dist(n, inf);
  dist[0] = 0LL;
  while (!s.empty()) {
    int x = s.begin() -> second;
    s.erase(s.begin());
    int add = 0;
    while (a[x].count(dist[x] + add) > 0) {
      add++;
    }
    for (auto e : g[x]) {
      int nd = dist[x] + e.second + add;
      if (dist[e.first] > nd) {
        s.erase({dist[e.first], e.first});
        dist[e.first] = nd;
        s.insert({dist[e.first], e.first});
      }
    }
  }
  cout << (dist[n - 1] == inf ? -1 : dist[n - 1]) << '\n';
  return 0;
}