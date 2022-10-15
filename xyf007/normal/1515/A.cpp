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
int t, n, x, a[101];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, x);
    for (int i = 1; i <= n; i++) Read(a[i]);
    std::sort(a + 1, a + n + 1);
    if (std::accumulate(a + 1, a + n + 1, 0) == x) {
      std::printf("NO\n");
    } else {
      std::printf("YES\n");
      int sum = 0;
      for (int i = 1; i <= n; i++)
        if (sum + a[i] != x) {
          sum += a[i];
        } else {
          std::swap(a[i], a[n]);
          break;
        }
      for (int i = 1; i <= n; i++) std::printf("%d%c", a[i], " \n"[i == n]);
    }
  }
  return 0;
}