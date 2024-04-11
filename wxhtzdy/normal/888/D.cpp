/**
 *    author:  milos
 *    created: 23.02.2021 09:08:12       
**/
#include <bits/stdc++.h>
 
using namespace std;

long long C(int n, int k) {                  
  vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= min(i, k); j++) {
      if (j == 0 || i == j) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
    }
  }
  return dp[n][k];  
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  long long ans = 0LL;
  for (int i = 0; i <= m; i++) {
    long long j = C(n, i);
    if (i == 1) j *= 0;
    if (i == 3) j *= 2;
    if (i == 4) j *= 9;
    ans += j;
  }
  cout << ans << '\n';
  return 0;
}