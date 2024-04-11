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
int p;
template <typename T>
T add(T a, T b) {
  return (a + b) % p;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + p - b) % p;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % p;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
template <typename T1, typename T2>
T1 Ksm(T1 a, T2 b) {
  T1 s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int c[101][101];
void Init(int n) {
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= n; j++) c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
  }
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, k, dp[102][101][101];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> k >> p, Init(n);
  for (int i = n + 1; i > 1; i--) {
    dp[i][0][0] = 1;
    std::vector<int> sta[101];
    for (int j0 = 0; j0 < n; j0++)
      for (int k0 = 0; k0 <= k; k0++)
        if (dp[i][j0][k0]) sta[j0].emplace_back(k0);
    for (int j0 = 0; j0 < n; j0++)
      for (auto &&k0 : sta[j0])
        for (int j1 = 0; j1 + j0 < n; j1++)
          for (auto &&k1 : sta[j1]) {
            if (k0 + k1 + (i - 1 == m) > k) break;
            Add(dp[i - 1][j0 + j1 + 1][k0 + k1 + (i - 1 == m)],
                mul(c[j0 + j1][j0], dp[i][j0][k0], dp[i][j1][k1]));
          }
  }
  std::cout << dp[1][n][k];
  return 0;
}