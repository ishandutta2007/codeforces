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
int n, pre[101], p[26];
long long k, dp[101][101];
char s[105];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k >> (s + 1);
  for (int i = 1; i <= n; i++) pre[i] = p[s[i] - 'a'], p[s[i] - 'a'] = i;
  dp[0][0] = 1LL;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1LL;
    for (int j = 1; j <= i; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
      if (pre[i]) dp[i][j] -= dp[pre[i] - 1][j - 1];
      checkmin(dp[i][j], 2 * k);
    }
  }
  long long ans = 0LL;
  for (int i = n; i >= 0; i--) {
    long long d = std::min(k, dp[n][i]);
    ans += d * (n - i);
    k -= d;
  }
  std::cout << (k ? -1 : ans);
  return 0;
}