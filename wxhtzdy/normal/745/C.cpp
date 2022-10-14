/**
 *    author:  wxhtzdy
 *    created: 19.07.2022 13:46:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> c(n);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    --x;
    c[x] = 1;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bool have;
  vector<bool> was(n);
  int sz;
  set<pair<int, int>> edges;
  function<void(int)> Dfs = [&](int v) {
    was[v] = true;
    sz += 1;
    if (c[v] == 1) {
      have = true;  
    }
    for (int u : g[v]) {
      edges.emplace(min(u, v), max(u, v));
      if (!was[u]) {
        Dfs(u);
      }
    }
  };
  vector<vector<pair<int, int>>> v(2);
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      have = false;
      sz = 0;
      edges.clear();
      Dfs(i);
      v[have].emplace_back(sz, edges.size());   
    }
  }
  long long ans = 0;
  for (int i = 0; i < 2; i++) {
    for (auto& p : v[i]) {
      long long mx = p.first * 1LL * (p.first - 1) / 2;
      ans += mx - p.second;
    }
  }
  sort(v[1].rbegin(), v[1].rend());
  for (auto& p : v[0]) {
    ans += p.first * v[1][0].first;
    v[1][0].first += p.first;
  }
  cout << ans << '\n';               
  return 0;
}