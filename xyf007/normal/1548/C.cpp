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
int n, q, s[3000015][4], fac[3000015], inv[3000015], iv[3000015];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q;
  fac[0] = iv[0] = iv[1] = 1;
  int N = 3 * n + 10;
  for (int i = 2; i <= N; i++) iv[i] = mul(kMod - kMod / i, iv[kMod % i]);
  for (int i = 1; i <= N; i++) fac[i] = mul(fac[i - 1], i);
  inv[N] = Ksm(fac[N], kMod - 2);
  for (int i = N - 1; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
  s[1][1] = mul(3 * n - 1, n, iv[2]);
  s[1][2] = mul(3 * n + 1, n, iv[2]);
  s[1][3] = mul(3 * n + 3, n, iv[2]);
  for (int i = 2; i <= 3 * n; i++) {
    int d21 = mul(i, s[i - 1][1]), d32 = mul(i, s[i - 1][2]),
        sum = mul(fac[3 * n + 1], inv[3 * n - i], iv[i + 1]);
    s[i][1] = mul(sub(sum, add(d21, d21, d32)), iv[3]);
    s[i][2] = add(s[i][1], d21);
    s[i][3] = add(s[i][2], d32);
  }
  while (q--) {
    int x;
    std::cin >> x;
    std::cout << mul(s[x][3], inv[x]) << '\n';
  }
  return 0;
}