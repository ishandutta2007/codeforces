/**
 *    author:  tourist
 *    created: 14.09.2019 16:19:46       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    vector<pair<int, int>> p(n * m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        p[i * m + j] = make_pair(~a[i][j], j);
      }
    }
    sort(p.begin(), p.end());
    vector<int> used(m, 0);
    int cnt = 0;
    for (int i = 0; i < n * m; i++) {
      int j = p[i].second;
      if (!used[j]) {
        ++cnt;
        used[j] = 1;
        if (cnt == n) {
          break;
        }
      }
    }
    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    for (int j = 0; j < m; j++) {
      if (!used[j]) {
        continue;
      }
      vector<int> here(1 << n, -1);
      for (int shift = 0; shift < n; shift++) {
        for (int t = 0; t < (1 << n); t++) {
          int sum = 0;
          for (int i = 0; i < n; i++) {
            if (t & (1 << i)) {
              sum += a[(shift + i) % n][j];
            }
          }
          here[t] = max(here[t], sum);
        }
      }
      for (int t = (1 << n) - 1; t >= 0; t--) {
        int nt = (1 << n) - 1 - t;
        int u = nt;
        while (u > 0) {
          if (dp[t] != -1) {
            dp[t | u] = max(dp[t | u], dp[t] + here[u]);
          }
          u = (u - 1) & nt;
        }
      }
    }
    cout << dp[(1 << n) - 1] << '\n';
  }
  return 0;
}