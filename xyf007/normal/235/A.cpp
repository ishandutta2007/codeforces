#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n;
void checkmax(long long &x, long long y) {
  if (x < y) {
    x = y;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  if (n == 1) {
    std::cout << 1;
  } else if (n == 2) {
    std::cout << 2;
  } else if (n & 1) {
    std::cout << n * static_cast<long long>(n - 1) * (n - 2);
  } else {
    long long ans = (n - 1) * static_cast<long long>(n - 2) * (n - 3);
    for (long long i = std::max(1, n - 50); i <= n; i++) {
      for (long long j = std::max(1, n - 50); j <= n; j++) {
        for (long long k = std::max(1, n - 50); k <= n; k++) {
          long long tmp = i / std::__gcd(i, j) * j;
          checkmax(ans, tmp / std::__gcd(tmp, k) * k);
        }
      }
    }
    std::cout << ans;
  }
  return 0;
}