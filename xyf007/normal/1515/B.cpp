#include <algorithm>
#include <cmath>
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
int t, n;
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n);
    if (n & 1) {
      std::printf("NO\n");
      continue;
    }
    int x = std::sqrt(n >> 1);
    if (x * x == (n >> 1)) {
      std::printf("YES\n");
    } else if (!(n % 4)) {
      x = std::sqrt(n >> 2);
      if (x * x == (n >> 2))
        std::printf("YES\n");
      else
        std::printf("NO\n");
    } else {
      std::printf("NO\n");
    }
  }
  return 0;
}