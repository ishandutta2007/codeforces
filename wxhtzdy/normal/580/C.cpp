/**
 *  author: milos
 *  created: 10.12.2020 23:59:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  deque<pair<int, int>> q;
  q.push_back({0, a[0]});
  vector<bool> was(n, false);
  was[0] = true;
  while (!q.empty()) {
    auto c = q[0];
    for (auto e : g[c.first]) {
      if (!was[e] && c.second + a[e] <= m) {
        was[e] = true;
        if (a[e] == 0) q.push_back({e, 0});
        else q.push_back({e, c.second + a[e]}); 
      }
    }
    q.pop_front();
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if ((int) g[i].size() == 1 && i != 0) {
      ans += was[i] == true;
    }  
  }
  cout << ans << '\n';
  return 0;
}