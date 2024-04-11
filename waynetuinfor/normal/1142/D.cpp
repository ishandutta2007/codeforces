#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> ch(11, vector<int>(11));
  for (int i = 0; i < 11; ++i) {
    for (int j = 0; j < 11; ++j) {
      for (int k = i; k < j + 11; ++k) ch[i][j] += k % 11;
    }
  }
  vector<vector<vector<vector<int>>>> dp(2, vector<vector<vector<int>>>(11, vector<vector<int>>(11, vector<int>(11))));
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int a = 0; a < 11; ++a) {
      for (int b = 0; b < 11; ++b) {
        for (int c = 0; c < 11; ++c) dp[i & 1 ^ 1][a][b][c] = 0;
      }
    }
    int dig = s[i] - '0';
    for (int a = dig + 1; a < 11; ++a) { 
      for (int b = 0; b < 11; ++b) {
        for (int c = 0; c < 11; ++c) {
          if (dp[i & 1][a][b][c] == 0) continue;
          // if (dig >= a) continue;
          int kv = ch[(b + 1) % 11][a], rv = ch[(b + 1) % 11][(c + 1) % 11];
          int na = (c + kv + dig + 1) % 11;
          int nb = c;
          int nc = (c + rv) % 11;
          dp[i & 1 ^ 1][na][nb][nc] += dp[i & 1][a][b][c];
          ans += dp[i & 1][a][b][c];
        }
      }
    }
    if (dig) {
      dp[i & 1 ^ 1][dig][0][9]++;
      ans++;
    }
  }
  cout << ans << "\n";
}