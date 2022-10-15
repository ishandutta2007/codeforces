#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) {
      return EOF;
    }
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9') {
    if (c == '-') {
      f = -1;
    }
  }
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') {
    x = x * 10 + c - '0';
  }
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) {
    x = y;
  }
}
struct Song {
  int l;
  double p;
} a[50001];
int n;
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) {
    Read(a[i].l, a[i].p);
    a[i].p /= 100;
  }
  std::sort(a + 1, a + n + 1, [](const Song &lhs, const Song &rhs) -> bool {
    return lhs.p * lhs.l * (1 - rhs.p) > rhs.p * rhs.l * (1 - lhs.p);
  });
  double ans = 0.0, lk = 0.0;
  for (int i = 1; i <= n; i++) {
    ans += a[i].l + lk * (1 - a[i].p);
    lk += a[i].l * a[i].p;
  }
  std::printf("%.11lf", ans);
  return 0;
}