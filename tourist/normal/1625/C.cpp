/**
 *    author:  tourist
 *    created: 12.01.2022 18:03:46       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l, k;
  cin >> n >> l >> k;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  d.push_back(l);
  a.push_back(0);
  const long long inf = (long long) 1e18;
  vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, inf));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int p = i - 1; p >= 0; p--) {
        int old_j = j - (i - p - 1);
        if (old_j >= 0) {
          dp[i][j] = min(dp[i][j], dp[p][old_j] + (d[i] - d[p]) * a[p]);
        }
      }
    }
  }
  cout << *min_element(dp.back().begin(), dp.back().end()) << '\n';
  return 0;
}