#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<vector<int>> dp(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    dp[i][0] = max((i == 0 ? 0 : dp[i - 1][0]) + b[i], (i == 0 ? (int) -1e9 : dp[i - 1][1]) + c[i]);
    dp[i][1] = max((i == 0 ? 0 : dp[i - 1][0]) + a[i], (i == 0 ? (int) -1e9 : dp[i - 1][1]) + b[i]);
  }
  cout << dp[n - 1][1] << '\n';
  return 0;
}