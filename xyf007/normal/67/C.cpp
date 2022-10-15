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
int n, m, ti, td, tr, te, dp[4001][4001], pos[26], pa[4001][26], pb[4001][26];
char s[4001], t[4001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> ti >> td >> tr >> te >> (s + 1) >> (t + 1);
  n = std::strlen(s + 1), m = std::strlen(t + 1);
  for (int i = 1; i <= n; i++) {
    std::memcpy(pa[i], pos, sizeof(pos));
    pos[s[i] - 'a'] = i;
  }
  std::memset(pos, 0, sizeof(pos));
  for (int i = 1; i <= m; i++) {
    std::memcpy(pb[i], pos, sizeof(pos));
    pos[t[i] - 'a'] = i;
  }
  std::memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      if (i) checkmin(dp[i][j], dp[i - 1][j] + td);
      if (j) checkmin(dp[i][j], dp[i][j - 1] + ti);
      if (i && j) checkmin(dp[i][j], dp[i - 1][j - 1] + (s[i] != t[j]) * tr);
      if (i > 1 && j > 1) {
        int x = pa[i][t[j] - 'a'], y = pb[j][s[i] - 'a'];
        if (x && y)
          checkmin(dp[i][j],
                   dp[x - 1][y - 1] + (i - x - 1) * td + te + (j - y - 1) * ti);
      }
    }
  std::cout << dp[n][m];
  return 0;
}