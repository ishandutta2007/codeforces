/**
 *    author:  wxhtzdy
 *    created: 19.09.2022 16:48:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (a[i] != b[i]);
    }
    if (cnt % 2 == 1) {
      cout << -1 << '\n';
      continue;      
    }
    vector<int> ids;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        ids.push_back(i);
      }
    }
    int k = (int) ids.size();
    if (k == 0) {      
      cout << 0 << '\n';
      continue;
    }
    const long long inf = 1e18;
    vector<long long> dp(k, inf);
    for (int r = 0; r < k; r++) {
      for (int l = r - 1; l >= 0; l -= 2) {
        long long prv_dp = (l > 0 ? dp[l - 1] : 0LL);
        long long cost = y * 1LL * ((r - l + 1) / 2);
        if (l + 1 == r && ids[l] + 1 == ids[r]) {
          cost = 2 * y;
        }    
        dp[r] = min(dp[r], prv_dp + cost);
      }
      if (r > 0) {
        dp[r] = min(dp[r], (r > 1 ? dp[r - 2] : 0LL) + (ids[r] - ids[r - 1]) * 1LL * x);
      }
    }
    cout << dp[k - 1] << '\n';
  }                                                                    
  return 0;
}