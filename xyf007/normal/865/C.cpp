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
int n, r, a[51], b[51];
double p[51], dp[55][5501];
bool Check(double mid) {
  for (int i = n; i >= 1; i--) {
    for (int j = r + 1; j <= 5500; j++) dp[i + 1][j] = mid;
    for (int j = r; j >= 0; j--)
      dp[i][j] = std::min(mid, (dp[i + 1][j + a[i]] + a[i]) * p[i] +
                                   (dp[i + 1][j + b[i]] + b[i]) * (1 - p[i]));
  }
  return dp[1][0] < mid;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> r;
  for (int i = 1; i <= n; i++) std::cin >> a[i] >> b[i] >> p[i], p[i] /= 100;
  double l = 0.0, r = 1e9;
  for (int i = 1; i <= 100; i++) {
    double mid = (l + r) / 2;
    (Check(mid) ? r : l) = mid;
  }
  std::cout << std::setprecision(11) << std::fixed << l;
  return 0;
}