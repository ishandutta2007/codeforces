#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) {
    x = y;
  }
}
int n, m, a[5001], dp[5001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m;
  double x;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> x;
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (a[j] <= a[i]) {
        checkmax(dp[i], dp[j] + 1);
      }
    }
  }
  std::cout << n - *std::max_element(dp + 1, dp + n + 1);
  return 0;
}