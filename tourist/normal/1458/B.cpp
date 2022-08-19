/**
 *    author:  tourist
 *    created: 19.12.2020 12:42:11       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    a[i] -= b[i];
  }
  int total = accumulate(b.begin(), b.end(), 0);
  vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j >= 0; j--) {
      for (int s = 0; s <= total; s++) {
        if (dp[j][s] != -1) {
          int ns = min(s + 2 * a[i] + b[i], total);
          dp[j + 1][ns] = max(dp[j + 1][ns], dp[j][s] + b[i]);
        }
      }
    }
  }
  for (int j = 1; j <= n; j++) {
    int ans = 0;
    for (int s = 0; s <= total; s++) {
      if (dp[j][s] != -1) {
        ans = max(ans, dp[j][s] + s);
      }
    }
    cout << fixed << setprecision(1) << 0.5 * ans << '\n';
  }
  return 0;
}