#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <iostream>
#include <numeric>
constexpr int kMod = 998244353;
template <typename T>
T add(T a, T b) {
  return a + b >= kMod ? a + b - kMod : a + b;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return a - b < 0 ? a - b + kMod : a - b;
}
template <typename T, typename... Args>
T sub(T a, T b, Args... args) {
  return sub(sub(a, b), args...);
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
  if ((a += b) >= kMod) a -= kMod;
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  if ((a -= b) < 0) a += kMod;
}
template <typename T, typename... Args>
void Sub(T &a, T b, Args... args) {
  Sub(a, add(b, args...));
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
int n, x, y, k, M, f[720721];
long long a[10000001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> a[0] >> x >> y >> k >> M;
  for (int i = 1; i < n; i++) a[i] = (a[i - 1] * x + y) % M;
  int lcm = 1;
  for (int i = 2; i < k; i++) lcm = std::lcm(lcm, i);
  int pw = 1;
  for (int i = k; i >= 1; i--) {
    for (int j = lcm; j >= 0; j--)
      f[j] = add(mul(n - 1, f[j]), mul(j, pw), f[j - j % i]);
    if (i > 1) Mul(pw, n);
  }
  long long ans = 0LL;
  for (int i = 0; i < n; i++)
    ans += (a[i] - a[i] % lcm) * pw % kMod * k + f[a[i] % lcm];
  std::cout << ans % kMod;
  return 0;
}