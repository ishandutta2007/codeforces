#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
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
int t, n, m, k;
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, m, k);
    if (n & 1) {
      k -= m >> 1;
      if (k < 0 || k & 1)
        std::printf("NO\n");
      else
        std::printf("YES\n");
    } else if (m & 1) {
      int kk = n * m / 2 - k - n / 2;
      if (kk < 0 || kk & 1)
        std::printf("NO\n");
      else
        std::printf("YES\n");
    } else {
      if (k & 1)
        std::printf("NO\n");
      else
        std::printf("YES\n");
    }
  }
  return 0;
}