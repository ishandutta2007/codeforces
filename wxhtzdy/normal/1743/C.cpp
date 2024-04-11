/**
 *    author:  wxhtzdy
 *    created: 18.10.2022 18:10:12
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
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }                  
    vector<vector<long long>> dp(n, vector<long long>(2));
    if (s[0] == '1') {
      dp[0][1] = a[0];
    }
    for (int i = 1; i < n; i++) {
      if (s[i] == '1') {
        dp[i][0] = dp[i - 1][0] + a[i - 1];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];  
      } else {           
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      }
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
  }                                                                    
  return 0;
}