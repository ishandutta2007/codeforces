#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
constexpr long long kP[] = {3, 15, 81, 6723, 50625, 2562991875};
constexpr int kSg[] = {0, 1, 2, 0, 3, 1, 2};
int n;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    long long x;
    std::cin >> x;
    ans ^= kSg[std::lower_bound(kP, kP + 6, x) - kP];
  }
  if (ans) {
    std::cout << "Furlo";
  } else {
    std::cout << "Rublo";
  }
  return 0;
}