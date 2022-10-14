/**
 *  author: milos
 *  created: 16.12.2020 02:01:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (i >= a) {
      if (dp[i - a] != 0 || i == a) {
        dp[i] = max(dp[i], dp[i - a] + 1);
      }  
    }
    if (i >= b) {
      if (dp[i - b] != 0 || i == b) {
        dp[i] = max(dp[i], dp[i - b] + 1);
      }  
    }
    if (i >= c) {
      if (dp[i - c] != 0 || i == c) {
        dp[i] = max(dp[i], dp[i - c] + 1);
      }  
    }
  }
  cout << dp[n] << '\n';
  return 0;
}