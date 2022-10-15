#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
constexpr int kMod = 1e9 + 7;
int n, m, a, b, pp, k, p[1501], sump[1501], fac[100001], inv[100001],
    f[1501][1501], g[1501][1501], sum[1501][1501];
int add(int a, int b) { return (a + b) % kMod; }
template <typename... Args>
int add(int a, int b, Args... args) {
  return add(add(a, b), args...);
}
int sub(int a, int b) { return (a + kMod - b) % kMod; }
int mul(int a, int b) { return a * static_cast<long long>(b) % kMod; }
template <typename... Args>
int mul(int a, int b, Args... args) {
  return mul(mul(a, b), args...);
}
void Add(int &a, int b) { a = add(a, b); }
template <typename... Args>
void Add(int &a, int b, Args... args) {
  Add(a, add(b, args...));
}
void Sub(int &a, int b) { a = sub(a, b); }
void Mul(int &a, int b) { a = mul(a, b); }
template <typename... Args>
void Mul(int &a, int b, Args... args) {
  Mul(a, mul(b, args...));
}
int Ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) {
      Mul(s, a);
    }
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int C(int x, int y) {
  if (x < y || y < 0) {
    return 0;
  }
  return mul(fac[x], inv[x - y], inv[y]);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m >> a >> b >> k;
  pp = mul(a, Ksm(b, kMod - 2));
  fac[0] = 1;
  for (int i = 1; i <= k; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
  inv[k] = Ksm(fac[k], kMod - 2);
  for (int i = k - 1; i >= 0; i--) {
    inv[i] = mul(inv[i + 1], i + 1);
  }
  for (int i = 0; i <= m && i <= k; i++) {
    p[i] = mul(C(k, i), Ksm(pp, i), Ksm(sub(1, pp), k - i));
  }
  std::partial_sum(p, p + m, sump + 1,
                   [](const int &x, const int &y) -> int { return add(x, y); });
  f[0][m] = sum[0][m] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] =
          mul(p[m - j], sub(mul(sub(sum[i - 1][m], sum[i - 1][m - j]), sump[j]),
                            g[i - 1][j]));
      sum[i][j] = add(sum[i][j - 1], f[i][j]);
      g[i][j] = add(g[i][j - 1], mul(p[j - 1], sum[i][j - 1]));
    }
  }
  std::cout << sum[n][m];
  return 0;
}