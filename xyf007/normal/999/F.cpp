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
int n, k, a[5001], b[501], h[11], cnt[100001], cp[100001], dp[501][5001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n * k; i++) std::cin >> a[i], cnt[a[i]]++;
  for (int i = 1; i <= n; i++) std::cin >> b[i], cp[b[i]]++;
  for (int i = 1; i <= k; i++) std::cin >> h[i];
  int ans = 0;
  for (int x = 1; x <= 100000; x++)
    if (cp[x]) {
      if (cnt[x] >= cp[x] * k) {
        ans += h[k] * cp[x];
        continue;
      }
      for (int i = 1; i <= cp[x]; i++) {
        std::memset(dp[i], 0, sizeof(dp[i]));
        for (int j = 0; j <= i * k && j <= cnt[x]; j++)
          for (int l = 0; l <= k && l <= j; l++)
            checkmax(dp[i][j], dp[i - 1][j - l] + h[l]);
      }
      ans += dp[cp[x]][cnt[x]];
    }
  std::printf("%d", ans);
  return 0;
}