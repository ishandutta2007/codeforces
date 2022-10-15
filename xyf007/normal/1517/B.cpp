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
int t, n, m, a[101][101];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, m);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) Read(a[i][j]);
    for (int i = 1; i <= m; i++) {
      int min = 0x7fffffff, px = -1, py = -1;
      for (int j = 1; j <= n; j++)
        for (int k = i; k <= m; k++)
          if (a[j][k] < min) {
            min = a[j][k];
            px = j;
            py = k;
          }
      std::swap(a[px][i], a[px][py]);
      for (int j = 1; j <= n; j++)
        if (j != px)
          std::swap(a[j][i],
                    a[j][std::max_element(a[j] + i, a[j] + m + 1) - a[j]]);
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) std::printf("%d%c", a[i][j], " \n"[j == m]);
  }
  return 0;
}