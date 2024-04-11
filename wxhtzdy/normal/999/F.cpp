/**
 *    author: m371
 *    created: 17.10.2021 21:58:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  const int MAX = 1e5 + 5;  
  vector<int> c(MAX);
  for (int i = 0; i < n * k; i++) {
    int x;
    cin >> x;
    c[x] += 1;
  }
  vector<int> f(MAX);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    f[x] += 1;
  }
  vector<int> h(k + 1);
  for (int i = 1; i <= k; i++) {
    cin >> h[i];
  }             
  int ans = 0;
  for (int i = 1; i < MAX; i++) {
    if (f[i] == 0 || c[i] == 0) {
      continue;
    }
    vector<vector<int>> dp(f[i] + 1, vector<int>(c[i] + 1));
    for (int x = 0; x < f[i]; x++) {
      for (int y = 0; y <= c[i]; y++) {
        for (int t = 0; t <= k; t++) {
          if (y + t <= c[i]) {
            dp[x + 1][y + t] = max(dp[x + 1][y + t], dp[x][y] + h[t]);
          }
        }
      }
    }
    ans += *max_element(dp[f[i]].begin(), dp[f[i]].end());
  }
  cout << ans << '\n';
  return 0;
}