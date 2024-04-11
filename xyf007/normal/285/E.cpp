#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
constexpr int kMod = 1e9 + 7;
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
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
int Ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int n, k, fac[1001], inv[1001], dp[1001][1001][2][2];
int C(int x, int y) {
  if (x < y || y < 0) return 0;
  return mul(fac[x], inv[x - y], inv[y]);
}
int main(int argc, char const *argv[]) {
  Read(n, k);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  inv[n] = Ksm(fac[n], kMod - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
  dp[1][0][0][0] = dp[1][1][0][1] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 0; j <= i; j++) {
      dp[i][j][0][0] =
          add(dp[i - 1][j][0][0], dp[i - 1][j][1][0], dp[i - 1][j - 1][0][0]);
      dp[i][j][0][1] = add(dp[i - 1][j - 1][0][0], dp[i - 1][j - 1][1][0]);
      dp[i][j][1][0] =
          add(dp[i - 1][j][0][1], dp[i - 1][j][1][1], dp[i - 1][j - 1][0][1]);
      dp[i][j][1][1] = add(dp[i - 1][j - 1][0][1], dp[i - 1][j - 1][1][1]);
    }
  int ans = 0;
  for (int i = k; i <= n; i++)
    (i - k) & 1
        ? Sub(ans,
              mul(add(dp[n][i][0][0], dp[n][i][1][0]), fac[n - i], C(i, k)))
        : Add(ans,
              mul(add(dp[n][i][0][0], dp[n][i][1][0]), fac[n - i], C(i, k)));
  std::printf("%d", ans);
  return 0;
}