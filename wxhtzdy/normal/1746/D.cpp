/**
 *    author:  wxhtzdy
 *    created: 15.10.2022 16:46:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int p;
      cin >> p;
      --p;
      g[p].push_back(i);
    }
    vector<long long> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<long long> dp(n);
    function<void(int)> Solve = [&](int v) {
      dp[v] = s[v];
      for (int u : g[v]) {
        Solve(u);
        dp[v] = max(dp[v], dp[u] + s[v]);
      }
    };
    Solve(0);
    long long ans = 0;
    fill(dp.begin(), dp.end(), 0LL);
    function<void(int, long long)> Dfs = [&](int v, long long p) {
      ans += (long long) s[v] * p;
      int deg = (int) g[v].size();
      dp[v] = s[v];
      /*vector<int> order(deg);
      iota(order.begin(), order.end(), 0);
      sort(order.begin(), order.end(), [&](int i, int j) {
        return dp[g[v][i]] > dp[g[v][j]];
      });*/
      if (deg == 0) {
        return;
      }
      long long all = p / deg;
      p %= deg; 
      for (int u : g[v]) {
        //int u = g[v][idx];
        Dfs(u, all);
        /*if (p > 0) {
          p -= 1;
        }*/
      }                        
      vector<int> order(deg);
      iota(order.begin(), order.end(), 0);
      sort(order.begin(), order.end(), [&](int i, int j) {
        return dp[g[v][i]] > dp[g[v][j]];
      });
      for (int i = 0; i < p; i++) {
        ans += dp[g[v][order[i]]];
      }
      for (int i = p; i < deg; i++) {
        dp[v] = max(dp[v], dp[g[v][order[i]]] + s[v]);
      }
    };
    Dfs(0, k);
    cout << ans << '\n';
  }                                                                    
  return 0;
}