#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
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
int n, d, a[101], x[101], y[101], dp[101], dis[101][101];
int main(int argc, char const *argv[]) {
  Read(n, d);
  for (int i = 2; i < n; i++) Read(a[i]);
  for (int i = 1; i <= n; i++) Read(x[i], y[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dis[i][j] = std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);
  std::memset(dp, 0x3f, sizeof(dp));
  dp[n] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        checkmin(dp[j], dp[k] + std::max(dis[j][k] * d - a[j], 0));
  std::printf("%d", dp[1]);
  return 0;
}