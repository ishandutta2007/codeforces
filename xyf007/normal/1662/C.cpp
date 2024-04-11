#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <cstddef>
#include <iostream>
constexpr int kMod = 998244353;
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, m, k, d[101];
class Matrix {
 public:
  Matrix() {
    for (int i = 1; i <= 2 * n; i++)
      std::fill(a_[i] + 1, a_[i] + 2 * n + 1, 0LL);
  }
  long long *operator[](std::size_t x) { return a_[x]; }
  const long long *operator[](std::size_t x) const { return a_[x]; }
  Matrix operator*(const Matrix &rhs) const {
    Matrix s;
    for (int i = 1; i <= 2 * n; i++)
      for (int k = 1; k <= 2 * n; k++)
        if (a_[i][k])
          for (int j = 1; j <= 2 * n; j++)
            s[i][j] += a_[i][k] * rhs[k][j] % kMod;
    for (int i = 1; i <= 2 * n; i++)
      for (int j = 1; j <= 2 * n; j++) s[i][j] %= kMod;
    return s;
  }
  Matrix &operator*=(const Matrix &rhs) { return *this = *this * rhs; }
  Matrix pow(int b) const {
    Matrix s, a = *this;
    for (int i = 1; i <= 2 * n; i++) s[i][i] = 1LL;
    while (b) {
      if (b & 1) s *= a;
      a *= a;
      b >>= 1;
    }
    return s;
  }

 private:
  long long a_[201][201];
};
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  Matrix tran, fin;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    tran[u][v] = tran[v][u] = fin[u][v] = fin[v][u] = 1LL;
    d[u]++, d[v]++;
  }
  for (int i = 1; i <= n; i++) {
    tran[i][i + n] = 1LL, tran[i + n][i] = kMod + 1 - d[i];
    fin[i + n][i] = kMod - d[i];
  }
  Matrix res = tran.pow(k - 1) * fin;
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) ans += res[i][i];
  std::cout << ans % kMod;
  return 0;
}