/**
 *    author:  wxhtzdy
 *    created: 11.10.2022 16:48:51
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
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    vector<bool> dp(n + 1);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
      if (dp[i - 1] && i + b[i] <= n) {
        dp[i + b[i]] = true;
      }
      if (i - b[i] - 1 >= 0) {
        dp[i] = (dp[i] | dp[i - b[i] - 1]);        
      }
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}