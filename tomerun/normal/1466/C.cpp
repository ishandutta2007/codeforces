#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <array>
#include <numeric>
#include <memory>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int solve() {
  string s;
  cin >> s;
  if (s.size() == 1) return 0;
  vector<vector<int>> dp(s.size() + 1, vector<int>(4, 1 << 29));
  dp[0][0] = 0;
  vector<bool> ch(s.size());
  for (int i = 0; i < s.size(); ++i) {
    ch[i] = ch[i] || (i < s.size() - 1 && s[i] == s[i + 1]);
    ch[i] = ch[i] || (i < s.size() - 2 && s[i] == s[i + 2]);
    ch[i] = ch[i] || (i > 0 && s[i] == s[i - 1]);
    ch[i] = ch[i] || (i > 1 && s[i] == s[i - 2]);
  }
  dp[0][0] = 0;
  dp[1][0] = 0;
  dp[1][2] = 1;
  if (s[0] != s[1]) {
    dp[2][0] = 0;
  }
  dp[2][1] = 1;
  dp[2][2] = 1;
  dp[2][3] = 2;
  for (int i = 2; i < s.size(); ++i) {
    for (int j = 0; j < 4; ++j) {
      dp[i + 1][2 | (j >> 1)] = min(dp[i + 1][2 | (j >> 1)], dp[i][j] + 1);
      if ((s[i] != s[i - 1] || (j & 2)) && (s[i] != s[i - 2] || (j & 1))) {
        dp[i + 1][j >> 1] = min(dp[i + 1][j >> 1], dp[i][j]);
      }
    }
  }
  int ans = dp[s.size()][0];
  ans = min(ans, dp[s.size()][1]);
  ans = min(ans, dp[s.size()][2]);
  ans = min(ans, dp[s.size()][3]);
  return ans;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << solve() << endl;
  }
}