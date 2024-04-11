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
int n, a[14], f[16384], inv[2000001];
std::unordered_map<int, int> g[16384];
std::vector<int> d[16384];
void Init(int n) {
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; i++) inv[i] = mul(kMod - kMod / i, inv[kMod % i]);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Init(2000000);
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  for (int S = 1; S < (1 << n); S++)
    for (int i = 0; i < n; i++)
      if ((S >> i) & 1) d[S].emplace_back(i);
  for (int S = 1; S < (1 << n); S++) {
    f[S] = 1;
    for (int T = (S - 1) & S; T; T = (T - 1) & S) {
      int X = T ^ S, pr = 1;
      for (std::size_t i = 0; i < d[T].size(); i++)
        for (std::size_t j = 0; j < d[X].size(); j++)
          Mul(pr, a[d[T][i]], inv[a[d[T][i]] + a[d[X][j]]]);
      Sub(f[S], mul(pr, f[T]));
    }
  }
  int ans = 0, full = (1 << n) - 1;
  for (int S = 1; S < (1 << n); S++) {
    int pr = 1, T = S ^ full;
    for (std::size_t i = 0; i < d[S].size(); i++)
      for (std::size_t j = 0; j < d[T].size(); j++)
        Mul(pr, a[d[S][i]], inv[a[d[S][i]] + a[d[T][j]]]);
    Add(ans, mul(pr, f[S], static_cast<int>(d[S].size())));
  }
  std::cout << ans;
  return 0;
}