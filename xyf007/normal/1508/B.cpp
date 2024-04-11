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
long long k;
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, k);
    if (n <= 61 && k > (1LL << (n - 1))) {
      std::printf("-1\n");
      continue;
    }
    // if (n == 1) {
    //   std::printf("1\n");
    //   continue;
    // }
    for (int i = 1; i <= n - 62; i++) std::printf("%d ", i);
    int st = std::max(1, n - 61);
    while (st <= n) {
      for (int i = st; i <= n; i++)
        if ((1LL << std::max(n - i - 1, 0)) < k) {
          k -= 1LL << std::max(n - i - 1, 0);
        } else {
          for (int j = i; j >= st; j--) std::printf("%d ", j);
          st = i + 1;
        }
    }
    std::printf("\n");
  }
  return 0;
}