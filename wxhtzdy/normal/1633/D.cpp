/**
 *    author:  wxhtzdy
 *    created: 01.02.2022 09:42:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = (int) 1e3 + 5;
  vector<int> dp(MAX, 1e9);
  dp[1] = 0;
  for (int i = 1; i < MAX; i++) {
    for (int x = 1; x <= i; x++) {
      int new_i = i + i / x;
      if (new_i < MAX) {
        dp[new_i] = min(dp[new_i], dp[i] + 1);
      }
    }
  }                                             
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    vector<int> a(n);
    long long ft = 0;
    for (int i = 0; i < n; i++) {
      a[i] = dp[b[i]];    
      if (a[i] == 0) {
        ft += c[i];
      }              
    }
    k = min(k, accumulate(a.begin(), a.end(), 0));              
    vector<long long> ans(k + 1);
    for (int j = 0; j < n; j++) {
      if (a[j] == 0) {
        continue;
      }
      auto nans = ans;
      for (int i = 0; i <= k; i++) {
        int old_i = i - a[j];
        if (old_i >= 0) {
          nans[i] = max(nans[i], ans[old_i] + c[j]);  
        }
      }
      swap(ans, nans);
    }                    
    cout << ans[k] + ft << '\n';
  }                                                                    
  return 0;
}