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
constexpr double kEps = 1e-8;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n;
double p, c[1001][1001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> p;
  c[0][0] = 1.0;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1.0;
    for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  }
  if (p < kEps) {
    std::cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    double pp =
        (c[i][1] * c[n - i][2] * 0.5 + c[i][2] * c[n - i][1] + c[i][3]) /
        c[n][3];
    if (pp - p > -kEps) {
      std::cout << i;
      return 0;
    }
  }
  return 0;
}