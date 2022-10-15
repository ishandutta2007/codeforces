#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
long long a, b;
int k, dp[360361];
void checkmin(int &x, int y) {
  if (x > y) {
    x = y;
  }
}
int Solve(int l, int r) {
  std::memset(dp, 0x3f, sizeof(dp));
  dp[r] = 0;
  for (int i = r; i > l; i--) {
    checkmin(dp[i - 1], dp[i] + 1);
    for (int j = 2; j <= k; j++) {
      if (i - i % j >= l) {
        checkmin(dp[i - i % j], dp[i] + 1);
      }
    }
  }
  return dp[l];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> a >> b >> k;
  int lcm = 1;
  for (int i = 1; i <= k; i++) {
    lcm = lcm / std::__gcd(lcm, i) * i;
  }
  if (a / lcm == b / lcm) {
    std::cout << Solve(b % lcm, a % lcm);
  } else {
    std::cout << Solve(0, a % lcm) + (a / lcm - b / lcm - 1) * Solve(0, lcm) +
                     Solve(b % lcm, lcm);
  }
  return 0;
}