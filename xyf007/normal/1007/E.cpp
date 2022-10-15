#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
constexpr long long kInf = 0x3f3f3f3f3f3f3f3fLL;
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, m, K;
long long a[205], b[205], c[205], f[205][205][2], g[205][205][2], A[205],
    B[205];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> K;
  for (int i = 1; i <= n; i++) std::cin >> a[i] >> b[i] >> c[i];
  n++, a[n] = b[n] = 1000000000, c[n] = kInf;
  std::memset(f, 0x3f, sizeof(f)), std::memset(g, 0x3f, sizeof(g));
  std::memset(f[0], 0, sizeof(f[0])), std::memset(g[0], 0, sizeof(g[0]));
  std::partial_sum(a + 1, a + n + 1, A + 1);
  std::partial_sum(b + 1, b + n + 1, B + 1);
  auto cl = [](long long x) { return (x + K - 1) / K; };
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; k < 2; k++) {
        if (k * a[i] + j * b[i] <= c[i] && f[i - 1][j][k] < kInf) {
          f[i][j][k] = f[i - 1][j][k];
          long long w = cl(k * A[i - 1] + j * B[i - 1]);
          if (w * K <= k * A[i] + j * B[i]) g[i][j][k] = w;
        }
        for (int r = 0; r < j; r++)
          if (g[i][r][k] < kInf) {
            long long t = k * A[i] + r * B[i] - K * g[i][r][k],
                      d = cl(std::max(t + (j - r) * b[i] - c[i], 0LL));
            if (d * K <= t && f[i - 1][j - r][0] < kInf) {
              checkmin(f[i][j][k], g[i][r][k] + d + f[i - 1][j - r][0]);
              long long w = cl((j - r) * B[i - 1]);
              if (w * k <= (j - r) * B[i] + t - d * k)
                checkmin(g[i][j][k], g[i][r][k] + d + w);
            }
          }
      }
  std::cout << f[n][m][1];
  return 0;
}