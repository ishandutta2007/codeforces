#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
constexpr int kMod = 1e9 + 7;
int n, k, fac[101], inv[101], dp[101][10001], f[101][101];
long long m;
int Ksm(int a, long long b) {
  int s = 1;
  while (b) {
    if (b & 1) {
      s = s * static_cast<long long>(a) % kMod;
    }
    a = a * static_cast<long long>(a) % kMod;
    b >>= 1;
  }
  return s;
}
long long C(int x, int y) {
  if (x < y || y < 0) {
    return 0LL;
  }
  return static_cast<long long>(fac[x]) * inv[x - y] % kMod * inv[y] % kMod;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * static_cast<long long>(i) % kMod;
  }
  inv[n] = Ksm(fac[n], kMod - 2);
  for (int i = n - 1; i >= 0; i--) {
    inv[i] = inv[i + 1] * static_cast<long long>(i + 1) % kMod;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      f[i][j] = Ksm(C(n, j), m / n + (i <= m % n));
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i * n && j <= k; j++) {
      for (int k = 0; k <= n && k <= j; k++) {
        dp[i][j] =
            (dp[i][j] + static_cast<long long>(dp[i - 1][j - k]) * f[i][k]) %
            kMod;
      }
    }
  }
  std::cout << dp[n][k];
  return 0;
}