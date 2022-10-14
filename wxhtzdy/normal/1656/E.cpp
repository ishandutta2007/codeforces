#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> ans(n);
    function<void(int, int, int)> Dfs = [&](int v, int pv, int d) {
      ans[v] = (d % 2 == 0 ? g[v].size() : -g[v].size());
      for (int u : g[v]) {
        if (u == pv) {
          continue;
        }
        Dfs(u, v, d + 1);
      }
    };
    Dfs(0, 0, 0);
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " "; 
      }
      cout << ans[i];
    }
    cout << '\n';
  }                                                                    
  return 0;
}