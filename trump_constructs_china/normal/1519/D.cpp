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
int n;
long long a[5001], b[5001];
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  for (int i = 1; i <= n; i++) Read(b[i]);
  long long ans = std::inner_product(a + 1, a + n + 1, b + 1, 0LL), sum = ans;
  for (int i = 1; i <= n; i++) {
    long long tmp = sum;
    for (int j = 1; j < i && j <= n - i; j++) {
      tmp -= a[i - j] * b[i - j] + a[i + j] * b[i + j];
      tmp += a[i - j] * b[i + j] + a[i + j] * b[i - j];
      checkmax(ans, tmp);
    }
  }
  for (int i = 1; i < n; i++) {
    long long tmp = sum;
    for (int j = 1; j <= i && j <= n - i; j++) {
      tmp -= a[i - j + 1] * b[i - j + 1] + a[i + j] * b[i + j];
      tmp += a[i - j + 1] * b[i + j] + a[i + j] * b[i - j + 1];
      checkmax(ans, tmp);
    }
  }
  std::printf("%lld", ans);
  return 0;
}