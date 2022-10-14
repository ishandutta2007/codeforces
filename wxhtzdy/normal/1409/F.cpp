#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  string t;
  cin >> s >> t;
  const int inf = (int) 1e9;
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(n + 1, -inf)));
  for (int c = 0; c < 26; c++) {
    char ch = (char) (c + 'a');
    int new_k = ch != s[0];
    if (new_k <= k) {
      dp[0][new_k][ch == t[0]] = 0;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int x = 0; x <= n; x++) {
        for (int c = 0; c < 26; c++) {
          char ch = (char) ('a' + c);
          int old_j = j - (s[i] != ch);
          int old_x = x - (t[0] == ch);
          int delta = (t[1] == ch ? old_x : 0);
          if (old_j >= 0 && old_x >= 0) {
            dp[i][j][x] = max(dp[i][j][x], dp[i - 1][old_j][old_x] + delta);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int j = 0; j <= k; j++) {
    ans = max(ans, *max_element(dp[n - 1][j].begin(), dp[n - 1][j].end()));
  }
  cout << ans << '\n';
  return 0;
}