/**
 *    author:  milos
 *    created: 30.09.2021 21:09:41       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, n1, n2, n3;
  cin >> n >> m >> n1 >> n2 >> n3;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bool bip = true;
  vector<int> col(n);
  vector<int> roots;
  vector<vector<vector<int>>> cols(n, vector<vector<int>>(3));
  function<void(int)> Dfs = [&](int u) {
    cols[roots.back()][col[u]].push_back(u);
    for (int v : g[u]) {
      if (col[v] == 0) {
        col[v] = (col[u] == 1 ? 2 : 1);
        Dfs(v);
      } else {
        if (col[v] == col[u]) {
          bip = false;
        }
      }
    }
  };
  vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
  dp[0][0] = true;  
  for (int i = 0; i < n; i++) {
    if (col[i] == 0) {
      roots.push_back(i);
      col[i] = 1;
      Dfs(i);
      int sz = roots.size();
      int x = cols[roots.back()][1].size();
      int y = cols[roots.back()][2].size();
      for (int j = 0; j <= n; j++) {
        if (j >= x) {
          dp[sz][j] = (dp[sz][j] | dp[sz - 1][j - x]);
        }
        if (j >= y) {
          dp[sz][j] = (dp[sz][j] | dp[sz - 1][j - y]);
        }
      }
    }
  }
  if (!bip || !dp[roots.size()][n2]) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  vector<int> ans(n); 
  function<void(int, int)> Rec = [&](int i, int j) {
    if (i == 0 || j == 0) return;
    for (int x : {cols[roots[i - 1]][1].size(), cols[roots[i - 1]][2].size()}) {
      if (j >= x && dp[i - 1][j - x]) {
        auto krc = (cols[roots[i - 1]][1].size() == x ? cols[roots[i - 1]][1] : cols[roots[i - 1]][2]);
        assert(krc.size() == x);
        for (int u : krc) {
          ans[u] = 2;
        }
        Rec(i - 1, j - x);
        return;
      }
    }
    //assert(false);
  };
  Rec(roots.size(), n2);
  for (int i = 0; i < n; i++) {
    if (ans[i] == 0) {
      if (n1 > 0) ans[i] = 1, n1--;
      else ans[i] = 3;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}