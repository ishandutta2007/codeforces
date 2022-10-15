#include <algorithm>
#include <cmath>
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
constexpr long double kEps = 1e-8;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, x, y, a[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    long double l = 0.0, r = 1e9;
    for (int t = 1; t <= 100; t++) {
      long double mid = (l + r) / 2.0;
      if (std::floor(mid * x) + std::floor(mid * y) >= a[i])
        r = mid;
      else
        l = mid;
    }
    bool f1 = std::fabs(l * x - std::round(l * x)) < kEps,
         f2 = std::fabs(l * y - std::round(l * y)) < kEps;
    if (f1 && f2)
      std::cout << "Both\n";
    else if (f1)
      std::cout << "Vanya\n";
    else
      std::cout << "Vova\n";
  }
  return 0;
}