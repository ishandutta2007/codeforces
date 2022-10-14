/**
 *    author:  wxhtzdy
 *    created: 13.07.2022 15:38:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    const int L = 60;
    const long long inf = 1e15;
    vector<long long> dp(L, -inf);
    dp[0] = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      vector<long long> new_dp(L, -inf);
      int x = a[i];
      for (int j = 0; j < L - 1; j++) {
        if (dp[j] > -inf) {
          new_dp[j] = max(new_dp[j], dp[j] - k + x);
          new_dp[j + 1] = max(new_dp[j + 1], dp[j] + x / 2);
        }
        x /= 2; 
      }                                 
      swap(dp, new_dp);     
      ans = max(ans, *max_element(dp.begin(), dp.end()));
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}