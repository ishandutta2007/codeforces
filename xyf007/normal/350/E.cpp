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
int n, m, k, a[301];
bool vis[301], e[301][301];
int main(int argc, char const *argv[]) {
  Read(n, m, k);
  for (int i = 1; i <= k; i++) {
    Read(a[i]);
    vis[a[i]] = true;
  }
  if (k == n || m > (n - 1) * (n - 2) / 2 + n - k) {
    std::printf("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    std::printf("%d %d\n", a[1], i);
    e[a[1]][i] = e[i][a[1]] = true;
  }
  int p = 1;
  while (vis[p]) p++;
  for (int i = 1; i <= n; i++)
    if (i != a[1] && vis[i]) {
      std::printf("%d %d\n", i, p);
      e[i][p] = e[p][i] = true;
    }
  m -= n - 1;
  for (int i = 1; i <= n && m; i++) {
    if (i == a[1]) continue;
    for (int j = 1; j <= n && m; j++) {
      if (j == i || j == a[1] || e[i][j]) continue;
      std::printf("%d %d\n", i, j);
      e[i][j] = e[j][i] = true;
      m--;
    }
  }
  return 0;
}