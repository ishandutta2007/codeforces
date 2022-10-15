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
int n, q, a[601][601];
void Dfs(int x, int y) {
  if (a[x][y] < 4) return;
  int t = a[x][y] >> 2;
  a[x][y] &= 3;
  a[x - 1][y] += t;
  a[x + 1][y] += t;
  a[x][y - 1] += t;
  a[x][y + 1] += t;
  Dfs(x - 1, y);
  Dfs(x + 1, y);
  Dfs(x, y - 1);
  Dfs(x, y + 1);
}
int main(int argc, char const *argv[]) {
  Read(n, q);
  a[300][300] = n;
  Dfs(300, 300);
  while (q--) {
    int x, y;
    Read(x, y);
    if (x < -300 || x > 300 || y < -300 || y > 300)
      std::printf("0\n");
    else
      std::printf("%d\n", a[x + 300][y + 300]);
  }
  return 0;
}