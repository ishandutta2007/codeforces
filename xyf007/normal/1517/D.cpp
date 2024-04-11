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
void Read(T &x, Args &... args) {
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
int n, m, k, a[501][501], b[501][501], dp[11][501][501];
int main(int argc, char const *argv[]) {
  Read(n, m, k);
  std::memset(a, 0x3f, sizeof(a));
  std::memset(b, 0x3f, sizeof(b));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < m; j++) Read(a[i][j]);
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= m; j++) Read(b[i][j]);
  if (k & 1) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) std::printf("-1%c", " \n"[j == m]);
    return 0;
  }
  k >>= 1;
  std::memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) dp[0][i][j] = 0;
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++)
      for (int l = 1; l <= m; l++) {
        if (j > 1) checkmin(dp[i][j - 1][l], dp[i - 1][j][l] + b[j - 1][l]);
        if (j < n) checkmin(dp[i][j + 1][l], dp[i - 1][j][l] + b[j][l]);
        if (l > 1) checkmin(dp[i][j][l - 1], dp[i - 1][j][l] + a[j][l - 1]);
        if (l < m) checkmin(dp[i][j][l + 1], dp[i - 1][j][l] + a[j][l]);
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      std::printf("%d%c", dp[k][i][j] << 1, " \n"[j == m]);
  return 0;
}