/**
 *    author:  wxhtzdy
 *    created: 16.08.2022 16:54:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }                 
    map<int, int> mp;
    int xr = 0;
    vector<int> dp(n, 1e9);
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
      xr ^= a[i];      
      dp[i] = (i == 0 ? 1 : dp[i - 1] + 1);
      if (mp.find(xr) != mp.end()) {
        dp[i] = min(dp[i], mp[xr] + i - 1);              
        mp[xr] = min(mp[xr], dp[i] - i);
      } else {
        mp[xr] = dp[i] - i;
      }
    }
    cout << dp[n - 1] << '\n';
  }                                                                    
  return 0;
}