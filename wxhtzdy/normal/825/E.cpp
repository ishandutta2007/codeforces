/**
 *    author: m371
 *    created: 10.10.2021 20:29:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> deg(n);
  vector<vector<int>> e(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    e[v].push_back(u);
    deg[u]++;
  }
  set<int> s;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      s.insert(i);
    }
  }
  vector<int> ans(n);
  for (int i = n; i >= 1; i--) {
    int u = *prev(s.end());
    s.erase(prev(s.end()));
    for (int j : e[u]) {
      deg[j]--;
      if (deg[j] == 0) {
        s.insert(j);
      }
    }
    ans[u] = i;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
  return 0;
}