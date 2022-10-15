#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
long long n, t, dp[101];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> t;
  n++;
  if (t & (t - 1)) {
    std::cout << 0;
    return 0;
  }
  int c = 0;
  for (int j = 60; j >= 0; j--) {
    for (int i = 60; i >= 1; i--) {
      dp[i] += dp[i - 1];
    }
    if ((n >> j) & 1) {
      dp[c++]++;
    }
  }
  dp[c]++;
  std::cout << dp[__builtin_ctzll(t) + 1] - (t == 1);
  return 0;
}