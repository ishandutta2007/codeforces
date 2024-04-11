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
int n, k, dp[405][405], c[405][405], inv[405], ans[2];
int C(int n, int m) {
  int s = 1;
  for (int i = n; i >= n - m + 1; i--) Mul(s, i);
  for (int i = 1; i <= m; i++) Mul(s, inv[i]);
  return s;
}
int main(int argc, char const *argv[]) {
  Read(n, k);
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= 2 * k; i++) inv[i] = mul(kMod - kMod / i, inv[kMod % i]);
  c[0][0] = 1;
  for (int i = 1; i <= 2 * k; i++) {
    c[i][0] = dp[i][0] = 1;
    for (int j = 1; j <= 2 * k; j++) {
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
      dp[i][j] = add(dp[i - 1][j], mul(dp[i - 1][j - 1], i - 1));
    }
  }
  ans[0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= 2 * k && j <= n; j++) {
      int tmp = 0;
      for (int l = 0; l <= j; l++)
        l & 1 ? Sub(tmp, mul(c[j][l], dp[j - l][i]))
              : Add(tmp, mul(c[j][l], dp[j - l][i]));
      Add(ans[i & 1], mul(C(n, j), tmp));
    }
    std::printf("%d ", ans[i & 1]);
  }
  return 0;
}