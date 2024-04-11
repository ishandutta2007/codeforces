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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
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
int n, k, a[4001][4001], sum[4001][4001], dp[801][4001];
int Calc(int l, int r) {
  return (sum[r][r] - sum[l - 1][r] - sum[r][l - 1] + sum[l - 1][l - 1]) >> 1;
}
void Solve(int x, int l, int r, int opl, int opr) {
  if (l > r) return;
  int mid = (l + r) >> 1, p = opl;
  for (int i = opl; i <= opr && i <= mid; i++)
    if (int s = dp[x - 1][i - 1] + Calc(i, mid); s < dp[x][mid]) {
      dp[x][mid] = s;
      p = i;
    }
  Solve(x, l, mid - 1, opl, p);
  Solve(x, mid + 1, r, p, opr);
}
int main(int argc, char const *argv[]) {
  Read(n, k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      Read(a[i][j]);
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }
  std::memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++) Solve(i, 1, n, 1, n);
  std::printf("%d", dp[k][n]);
  return 0;
}