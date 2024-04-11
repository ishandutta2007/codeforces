/**
 *    author:  milos
 *    created: 18.09.2021 09:27:32       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    if (g[i].size() > g[mx].size()) {
      mx = i;
    }
  }
  vector<int> que(1, mx);
  vector<bool> was(n, false);
  was[mx] = true;
  vector<pair<int, int>> ans;
  for (int i = 0; i < que.size(); i++) {
    int j = que[i];
    for (int x : g[j]) {
      if (!was[x]) {
        ans.push_back({j, x});
        que.push_back(x);
        was[x] = true;
      }
    }
  }
  assert(ans.size() == n - 1);
  for (int i = 0; i < n - 1; i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';  
  }
  return 0;
}