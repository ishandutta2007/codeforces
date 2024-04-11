/**
 *    author:  milos
 *    created: 28.01.2021 00:43:15       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<vector<bool>> p(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    p[i][i] = true;
  }
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      p[i][i + 1] = true;
    }
  }
  for (int i = 3; i <= n; i++) {
    for (int j = 0; j <= n - i; j++) {
      if (s[j] == s[j + i - 1] && p[j + 1][j + i - 2]) {
        p[j][j + i - 1] = true;
      }
    }                           
  }
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    dp[i][i + 1] = 2 + p[i][i + 1];
  }
  for (int i = 3; i <= n; i++) {
    for (int j = 0; j <= n - i; j++) {
      dp[j][j + i - 1] = dp[j][j + i - 2] + dp[j + 1][j + i - 1] - dp[j + 1][j + i - 2] + p[j][j + i - 1];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << dp[l][r] << '\n';
  }
  return 0;
}