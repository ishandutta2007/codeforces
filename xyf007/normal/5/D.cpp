#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
double a, v, l, w, d;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> a >> v >> l >> d >> w;
  if (v <= w) {
    if (v * v / 2 / a > l)
      std::cout << std::setprecision(8) << std::fixed << std::sqrt(2 * l / a);
    else
      std::cout << std::setprecision(8) << std::fixed
                << v / a + (l - v * v / 2 / a) / v;
    return 0;
  }
  double vt = std::sqrt(2 * a * d);
  if (vt <= w) {
    if (v * v / 2 / a > l)
      std::cout << std::setprecision(8) << std::fixed << std::sqrt(2 * l / a);
    else
      std::cout << std::setprecision(8) << std::fixed
                << v / a + (l - v * v / 2 / a) / v;
    return 0;
  }
  double s0 = (2 * v * v - w * w) / 2 / a, ans = 0.0;
  if (s0 <= d) {
    ans = (2 * v - w) / a + (d - s0) / v;
  } else {
    double x = std::sqrt(a * d + w * w / 2);
    ans = (2 * x - w) / a;
  }
  double s1 = (v * v - w * w) / 2 / a;
  if (l - d >= s1) {
    ans += (v - w) / a + (l - d - s1) / v;
  } else {
    double vl = std::sqrt(2 * a * (l - d) + w * w);
    ans += (vl - w) / a;
  }
  std::cout << std::setprecision(8) << std::fixed << ans;
  return 0;
}