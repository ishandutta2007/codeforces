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
int n, m, k;
long long a[301][301], dp[301][301];
int main(int argc, char const *argv[]) {
  Read(n, m, k);
  std::memset(a, 0x3f, sizeof(a));
  std::memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= m; i++) {
    int l, r;
    long long c;
    Read(l, r, c);
    for (int j = l; j <= r; j++)
      for (int o = j; o <= r; o++) checkmin(a[j][o], c);
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= i; j++) {
      checkmin(dp[i][j], dp[i - 1][j]);
      for (int o = 1; o <= j; o++)
        checkmin(dp[i][j], dp[i - o][j - o] + a[i - o + 1][i]);
    }
  if (dp[n][k] >= 1e18)
    std::printf("-1");
  else
    std::printf("%lld", dp[n][k]);
  return 0;
}