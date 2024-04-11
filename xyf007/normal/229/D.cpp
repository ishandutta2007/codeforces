#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, a[5001], dp[5001], sum[5001], min[5001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::memset(dp, 0x3f, sizeof(dp));
  std::memset(min, 0x3f, sizeof(min));
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::partial_sum(a + 1, a + n + 1, sum + 1);
  dp[0] = min[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (sum[i] - sum[j] >= min[j]) {
        if (dp[j] + i - j - 1 <= dp[i]) {
          dp[i] = dp[j] + i - j - 1;
          min[i] = sum[i] - sum[j];
        }
      }
    }
  }
  std::cout << dp[n];
  return 0;
}