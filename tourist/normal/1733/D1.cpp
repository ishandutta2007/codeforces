/**
 *    author:  tourist
 *    created: 19.09.2022 17:41:21       
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x, y;
    cin >> n >> x >> y;
    string a;
    string b;
    cin >> a >> b;
    vector<int> mis;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        mis.push_back(i);
      }
    }
    if (mis.size() % 2 == 1) {
      cout << -1 << '\n';
      continue;
    }
    if (x >= y) {
      if (mis.size() == 2 && mis[0] + 1 == mis[1]) {
        cout << min(x, 2 * y) << '\n';
        continue;
      }
      cout << y * (long long) (mis.size() / 2) << '\n';
      continue;
    }
    int sz = (int) mis.size();
    vector<long long> dp(sz + 1);
    for (int i = 1; i <= sz; i++) {
      dp[i] = dp[i - 1];
      if (i >= 2) {
        long long dist = mis[i - 1] - mis[i - 2];
        long long save = y - (long long) x * dist;
        dp[i] = max(dp[i], dp[i - 2] + save);
      }
    }
    cout << y * (long long) (mis.size() / 2) - dp[sz] << '\n';
  }
  return 0;
}