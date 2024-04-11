#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 1;
const int A = 26;

int dp[N][N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s, t;
  cin >> n >> k >> s >> t;

  memset(dp, -1, sizeof dp);
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (dp[i][j][k] != -1) {
          for (int c = 0; c < A; ++c) {
            int cost = (s[i] - 'a' != c);
            int bonus = (t[0] - 'a' == c);
            dp[i + 1][j + cost][k + bonus] = max(dp[i + 1][j + cost][k + bonus], dp[i][j][k] + (t[1] - 'a' == c ? k : 0));
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) {
      ans = max(ans, dp[n][i][j]);
    }
  }
  cout << ans << "\n";
}