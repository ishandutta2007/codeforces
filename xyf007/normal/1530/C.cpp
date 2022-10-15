#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
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
int t, n, a[400001], b[400001];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n);
    for (int i = 1; i <= n; i++) Read(a[i]);
    for (int i = 1; i <= n; i++) Read(b[i]);
    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + n + 1, std::greater<int>());
    int sa = std::accumulate(a + n / 4 + 1, a + n + 1, 0),
        sb = std::accumulate(b + 1, b + n - n / 4 + 1, 0), now = n - n / 4;
    if (sa >= sb) {
      std::printf("0\n");
      continue;
    }
    for (int i = n + 1;; i++) {
      sa += a[i] = 100;
      b[i] = 0;
      if (i % 4) now++, sb += b[now];
      if (!(i % 4)) sa -= a[i >> 2];
      if (sa >= sb) {
        std::printf("%d\n", i - n);
        break;
      }
    }
  }
  return 0;
}