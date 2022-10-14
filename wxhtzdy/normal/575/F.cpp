/**
 *    author:  milos
 *    created: 31.08.2021 10:25:05       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }                    
  vector<int> a(1, x);
  for (int i = 0; i < n; i++) {
    a.push_back(l[i]);
    a.push_back(r[i]);
  }
  sort(a.begin(), a.end());
  int m = a.size();           
  vector<long long> dp(m);
  for (int i = 0; i < m; i++) {
    dp[i] = abs(a[i] - x);  
  }
  for (int i = 0; i < n; i++) {
    vector<long long> new_dp(m);
    for (int j = 0; j < m; j++) {
      if (a[j] < l[i]) {
        new_dp[j] = dp[j] + l[i] - a[j];
      } else if (a[j] > r[i]) {
        new_dp[j] = dp[j] + a[j] - r[i];
      } else {
        new_dp[j] = dp[j];
      }
    }
    long long mn = 1e18;
    for (int j = 0; j < m; j++) {
      new_dp[j] = min(new_dp[j], mn);
      if (a[j] >= l[i]) {
        break;
      }
      mn = min(mn, new_dp[j]);
    }
    mn = 1e18;
    for (int j = m - 1; j >= 0; j--) {
      new_dp[j] = min(new_dp[j], mn);
      if (a[j] <= r[i]) {
        break;
      }
      mn = min(mn, new_dp[j]);
    }
    swap(dp, new_dp);  
  }
  long long ans = 1e18;
  for (int i = 0; i < m; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}