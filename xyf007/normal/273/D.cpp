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
int n, m, dp[151][151][2][2];
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= m; i++)
    for (int j = i; j <= m; j++) dp[i][j][1][1] = 1;
  int ans = 0;
  for (int k = 1; k <= n; k++) {
    int s = 0;
    for (int i = 1; i <= m; i++)
      for (int j = i; j <= m; j++)
        for (int l = 0; l <= 1; l++)
          for (int r = 0; r <= 1; r++) Add(s, dp[i][j][l][r]);
    Add(ans, mul(s, n - k + 1));
    for (int i = 1; i < m; i++) {
      for (int j = i + 1; j <= m; j++)
        for (int r = 0; r <= 1; r++)
          Add(dp[i + 1][j][0][r], dp[i][j][0][r], dp[i][j][1][r]);
      for (int j = m; j > i; j--)
        for (int l = 0; l <= 1; l++)
          Add(dp[i][j - 1][l][0], dp[i][j][l][0], dp[i][j][l][1]);
    }
    for (int i = m; i >= 2; i--)
      for (int j = i; j <= m; j++)
        for (int r = 0; r <= 1; r++) Add(dp[i - 1][j][1][r], dp[i][j][1][r]);
    for (int i = m - 1; i >= 1; i--)
      for (int j = i; j < m; j++)
        for (int l = 0; l <= 1; l++) Add(dp[i][j + 1][l][1], dp[i][j][l][1]);
  }
  std::printf("%d", ans);
  return 0;
}