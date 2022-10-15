#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, dp[201][201][201];
std::tuple<int, int, int> pre[201][201][201];
char s[201], t[201];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> (s + 1) >> (t + 1);
  n = std::strlen(s + 1), m = std::strlen(t + 1);
  std::memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= 200; k++) {
        int ni, nj;
        if (k < 200) {
          ni = i + (i < n && s[i + 1] == '(');
          nj = j + (j < m && t[j + 1] == '(');
          if (dp[i][j][k] + 1 < dp[ni][nj][k + 1])
            dp[ni][nj][k + 1] = dp[i][j][k] + 1, pre[ni][nj][k + 1] = {i, j, k};
        }
        if (k) {
          ni = i + (i < n && s[i + 1] == ')');
          nj = j + (j < m && t[j + 1] == ')');
          if (dp[i][j][k] + 1 < dp[ni][nj][k - 1])
            dp[ni][nj][k - 1] = dp[i][j][k] + 1, pre[ni][nj][k - 1] = {i, j, k};
        }
      }
  for (int T = 0; T <= 200; T++)
    for (int k = 0; k <= 200; k++) {
      if (k < 200) {
        if (dp[n][m][k] + 1 < dp[n][m][k + 1])
          dp[n][m][k + 1] = dp[n][m][k] + 1, pre[n][m][k + 1] = {n, m, k};
      }
      if (k) {
        if (dp[n][m][k] + 1 < dp[n][m][k - 1])
          dp[n][m][k - 1] = dp[n][m][k] + 1, pre[n][m][k - 1] = {n, m, k};
      }
    }
  std::string ans;
  std::tuple<int, int, int> now{n, m, 0};
  while (now != std::tuple<int, int, int>(0, 0, 0)) {
    auto [x, y, k] = now;
    auto [x0, y0, k0] = pre[x][y][k];
    ans += "()"[k < k0];
    now = pre[x][y][k];
  }
  std::reverse(ans.begin(), ans.end());
  std::cout << ans;
  return 0;
}