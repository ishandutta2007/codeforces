#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &... args) {
  Read(x), Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int t, n, k, a[2001], dp[2001][2001];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, k);
    for (int i = 1; i <= n; i++) Read(a[i]);
    std::memset(dp, 0xcf, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= i; j++) {
        checkmax(dp[i][j], dp[i - 1][j] + (i - a[i] == j));
        if (j) checkmax(dp[i][j], dp[i - 1][j - 1]);
      }
    int ans = n + 1;
    for (int i = 0; i <= n; i++)
      if (dp[n][i] >= k) checkmin(ans, i);
    std::printf("%d\n", ans == n + 1 ? -1 : ans);
  }
  return 0;
}