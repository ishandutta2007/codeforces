#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
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
  if (n == 2) {            
    cout << 2 << " " << 2 << '\n';
    cout << 1 << " " << 1 << '\n';
    return 0;
  }       
  vector<vector<int>> dp(n, vector<int>(2));
  vector<vector<int>> mn(n, vector<int>(2));
  function<void(int, int)> Solve = [&](int u, int p) {
    dp[u][1] = 1;
    mn[u][1] = g[u].size();
    for (int v : g[u]) {
      if (v == p) {
        continue;
      }       
      Solve(v, u);
      if (dp[v][0] < dp[v][1]) {
        dp[u][0] += dp[v][1];
        mn[u][0] += mn[v][1];  
      } else if (dp[v][0] == dp[v][1]) {
        dp[u][0] += dp[v][0];
        mn[u][0] += min(mn[v][0], mn[v][1]);
      } else {
        dp[u][0] += dp[v][0];
        mn[u][0] += mn[v][0];  
      }
      dp[u][1] += dp[v][0];
      mn[u][1] += mn[v][0];
    }
  };
  Solve(0, 0);
  cout << max(dp[0][0], dp[0][1]) << " ";
  vector<int> a;
  function<void(int, int, int)> Rec = [&](int u, int p, int c) {
    int col = 0;                                                
    if (c == 1 && (dp[u][0] < dp[u][1] || (dp[u][0] == dp[u][1] && mn[u][0] >= mn[u][1]))) {
      col = 1;
    }
    if (col == 1) {
      a.push_back(u);
    }             
    for (int v : g[u]) {
      if (v == p) {
        continue;
      }
      Rec(v, u, (col == 0 ? 1 : 0));
    }
  };
  Rec(0, 0, 1);
  vector<int> ans(n, 1);
  for (int x : a) {
    ans[x] = g[x].size();
  }
  cout << accumulate(ans.begin(), ans.end(), 0) << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}