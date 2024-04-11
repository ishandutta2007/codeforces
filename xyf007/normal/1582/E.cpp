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
int T, n, len[1001], slen[1001];
long long a[100001], sum[100001], dp[100001][500];
bool Check(int k) {
  std::memset(dp[0] + 1, 0x3f, 8 * k);
  dp[0][0] = 0LL;
  for (int i = 1; i <= k; i++) len[i] = k - i + 1;
  std::partial_sum(len + 1, len + k + 1, slen + 1);
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 0LL;
    for (int j = 1; j <= k; j++) {
      if (i < slen[j]) {
        dp[i][j] = 0x3f3f3f3f3f3f3f3fLL;
        continue;
      }
      dp[i][j] = dp[i - 1][j];
      if (sum[i] - sum[i - len[j]] > dp[i - len[j]][j - 1])
        checkmin(dp[i][j], sum[i] - sum[i - len[j]]);
    }
  }
  return dp[n][k] < 0x3f3f3f3f3f3f3f3fLL;
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::partial_sum(a + 1, a + n + 1, sum + 1);
  int l = 1, r = 0, best = 1;
  while ((r + 1) * (r + 2) / 2 <= n) r++;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (Check(mid))
      best = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  std::cout << best << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}