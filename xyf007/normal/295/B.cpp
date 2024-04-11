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
int n, e[501][501], a[501][501], id[501], dis[501][501];
long long ans[501];
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) Read(e[i][j]);
  for (int i = n; i >= 1; i--) Read(id[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = e[id[i]][id[j]];
  for (int i = 1; i <= n; i++) std::memcpy(e[i] + 1, a[i] + 1, 4 * n);
  std::memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= n; i++) dis[i][i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++)
      for (int k = 1; k < i; k++) {
        checkmin(dis[j][i], dis[j][k] + e[k][i]);
        checkmin(dis[i][j], e[i][k] + dis[k][j]);
      }
    for (int j = 1; j < i; j++)
      for (int k = 1; k < i; k++) checkmin(dis[j][k], dis[j][i] + dis[i][k]);
    for (int j = 1; j <= i; j++)
      for (int k = 1; k <= i; k++) ans[n - i + 1] += dis[j][k];
  }
  for (int i = 1; i <= n; i++) std::printf("%lld ", ans[i]);
  return 0;
}