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
int n, k;
long long a[2001][2001];
int main(int argc, char const *argv[]) {
  Read(n, k);
  for (int i = 1; i <= n; i++) a[i][i] = -1;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      Read(a[i][j]);
      a[j][i] = a[i][j];
    }
  long long ans = 0;
  if (k != 2) {
    for (int i = 1; i <= n; i++)
      ans += std::accumulate(
          a[i] + 1, a[i] + n + 1, 0LL,
          [](const long long &lhs, const long long &rhs) -> long long {
            return rhs == -1 ? lhs : lhs + rhs;
          });
    std::printf("%lld\n", ans / n);
  } else {
    for (int i = 1; i <= n; i++) {
      std::ptrdiff_t cnt = std::count_if(
          a[i] + 1, a[i] + n + 1, [](const int &lhs) -> bool { return ~lhs; });
      ans += std::accumulate(
                 a[i] + 1, a[i] + n + 1, 0LL,
                 [](const long long &lhs, const long long &rhs) -> long long {
                   return rhs == -1 ? lhs : lhs + rhs;
                 }) *
             (cnt - 1);
    }
    std::printf("%lld\n", ans * 2 / n / (n - 1));
  }
  return 0;
}