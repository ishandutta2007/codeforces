/**
 *    author:  tourist
 *    created: 12.08.2020 18:27:04       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<vector<int>> g(n);
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
    ans += t[x] + t[y];
  }
  vector<vector<long long>> dp(n, vector<long long>(2, -1));
  function<void(int, int)> Dfs = [&](int v, int pr) {
    vector<long long> costs;
    vector<int> c(2, 0);
    long long add = 0;
    for (int u : g[v]) {
      if (u == pr) {
        continue;
      }
      Dfs(u, v);
      if (dp[u][0] == -1) {
        assert(dp[u][1] != -1);
        c[1] += 1;
        add += dp[u][1];
        continue;
      }
      if (dp[u][1] == -1) {
        assert(dp[u][0] != -1);
        c[0] += 1;
        add += dp[u][0];
        continue;
      }
      assert(h[u] == h[v]);
      c[0] += 1;
      add += dp[u][0];
      costs.push_back(dp[u][1] - dp[u][0]);
    }
    sort(costs.rbegin(), costs.rend());
    for (int my = 0; my < 2; my++) {
      if (my == 0 && (pr != -1 && h[v] < h[pr])) {
        continue;
      }
      if (my == 1 && (pr == -1 || h[v] > h[pr])) {
        continue;
      }
      int k0 = c[0] + (my == 1 && pr != -1);
      int k1 = c[1] + (my == 0 && pr != -1);
      long long sum = 0;
      long long mx = -1;
      for (int hire = 0; hire <= (int) costs.size(); hire++) {
        long long cur = t[v] * min(k0, k1);
        mx = max(mx, cur + sum);
        if (hire == (int) costs.size()) {
          break;
        }
        sum += costs[hire];
        k0 -= 1;
        k1 += 1;
      }
      dp[v][my] = mx + add;
    }
  };
  Dfs(0, -1);
  cout << ans - dp[0][0] << '\n';
  return 0;
}