/**
 *    author:  wxhtzdy
 *    created: 23.08.2022 12:38:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m, c0, d0;
  cin >> n >> m >> c0 >> d0;
  vector<int> a(m), b(m), c(m), d(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  vector<int> dp(n + 1);
  for (int i = c0; i <= n; i += c0) {
    dp[i] = (i / c0) * d0;
  }
  for (int i = 0; i < m; i++) {
    auto new_dp = dp;
    for (int k = 0; k <= n; k++) {
      for (int take = 1; take * b[i] <= a[i] && k + take * c[i] <= n; take++) {
        new_dp[k + take * c[i]] = max(new_dp[k + take * c[i]], dp[k] + take * d[i]);
      }
    }
    swap(dp, new_dp);
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';                               
  return 0;
}