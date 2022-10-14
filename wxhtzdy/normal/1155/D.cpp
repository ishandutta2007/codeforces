/**
 *  author: milos
 *  created: 26.12.2020 18:46:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(3, vector<long long>(3, 0)));
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      dp[i][0][0] = 0;
      dp[i][1][0] = a[i];
      dp[i][1][1] = a[i] * x;
      dp[i][1][2] = a[i];
      dp[i][2][0] = max({(long long) 0, dp[i][1][0], dp[i][1][1], dp[i][1][2]});
    } else {
      dp[i][0][0] = 0;
      dp[i][1][0] = max(dp[i - 1][1][0] + a[i], dp[i - 1][0][0] + a[i]);
      dp[i][1][1] = max({dp[i - 1][0][0] + a[i] * x, dp[i - 1][1][1] + a[i] * x, dp[i - 1][1][0] + a[i] * x});
      dp[i][1][2] = max({dp[i - 1][0][0] + a[i], dp[i - 1][1][1] + a[i], dp[i - 1][1][2] + a[i]});
      dp[i][2][0] = max({(long long) 0, dp[i][1][0], dp[i][1][1], dp[i][1][2], dp[i - 1][2][0]}); 
    }
  }
  cout << dp[n - 1][2][0] << '\n';  
  return 0;
}