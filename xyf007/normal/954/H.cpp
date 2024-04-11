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
constexpr int kMod = 1e9 + 7;
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
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
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, a[5001], s[5001], iv[5001], f[5001][10001], ans[10001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n, n--;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  s[0] = 1;
  std::partial_sum(a + 1, a + n + 1, s + 1, [](const int &lhs, const int &rhs) {
    return mul(lhs, rhs);
  });
  for (int i = 0; i <= n; i++) iv[i] = Ksm(s[i], kMod - 2);
  auto g = [](int x, int y) {
    return x && y >= 0 && x + y - 1 <= n ? mul(s[x + y - 1], iv[x - 1]) : 0;
  };
  for (int i = 2; i <= n + 1; i++)
    for (int j = 1; j <= 2 * n; j++)
      f[i][j] = add(f[i - 1][j - 1], g(i - 1, j - 1), kMod - g(i, j - 2));
  for (int i = 1; i <= n + 1; i++)
    for (int j = 1; j <= 2 * n; j++)
      Add(ans[j], mul(s[i - 1], f[i][j] + g(i, j)));
  for (int i = 1; i <= 2 * n; i++) std::cout << mul(ans[i], 500000004) << ' ';
  return 0;
}