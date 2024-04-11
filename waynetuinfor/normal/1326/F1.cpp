#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      adj[i][j] = s[j] - '0';
    }
  }
  vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(1 << n));
  for (int i = 0; i < n; ++i) {
    for (int s = 1; s < (1 << n); ++s) {
      int bit = __builtin_popcount(s) - 1;
      dp[i][s].resize(1 << bit);
    }
    dp[i][1 << i][0] = 1;
  }
  for (int s = 1; s < (1 << n); ++s) {
    for (int i = 0; i < n; ++i) {
      int bit = __builtin_popcount(s) - 1;
      for (int j = 0; j < (1 << bit); ++j) {
        if (dp[i][s][j] == 0) continue;
        for (int k = 0; k < n; ++k) {
          if ((s >> k & 1) == 0) {
            dp[k][s ^ (1 << k)][j | adj[i][k] << bit] += dp[i][s][j];
          }
        }
      }
    }
  }
  for (int s = 0; s < (1 << (n - 1)); ++s) {
    int64_t res = 0;
    for (int i = 0; i < n; ++i) {
      res += dp[i][(1 << n) - 1][s];
    }
    cout << res << " ";
  }
  return 0;
}