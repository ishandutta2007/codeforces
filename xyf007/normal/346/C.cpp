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
int n, a[100001], x, y;
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  Read(x, y);
  std::sort(a + 1, a + n + 1);
  n = std::unique(a + 1, a + n + 1) - a - 1;
  int ans = 0;
  while (x > y) {
    int min = x - 1;
    for (int i = 1; i <= n; i++) {
      int t = x - x % a[i];
      if (t < y)
        a[i--] = a[--n];
      else
        checkmin(min, t);
    }
    x = min;
    ans++;
  }
  std::printf("%d", ans);
  return 0;
}