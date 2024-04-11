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
int n, m, k, a[100001], b[100001];
int main(int argc, char const *argv[]) {
  Read(n, m, k);
  if (n > m) {
    std::printf("YES");
    return 0;
  }
  for (int i = 1; i <= n; i++) Read(a[i]);
  for (int i = 1; i <= m; i++) Read(b[i]);
  std::sort(a + 1, a + n + 1, std::greater<int>());
  std::sort(b + 1, b + m + 1, std::greater<int>());
  for (int i = 1; i <= n; i++)
    if (a[i] > b[i]) {
      std::printf("YES");
      return 0;
    }
  std::printf("NO");
  return 0;
}