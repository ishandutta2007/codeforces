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
int n, m;
long long a[100001], b[100001];
bool Check(long long x) {
  int p = 1;
  for (int i = 1; i <= n; i++) {
    if (p > m) return true;
    if (std::abs(a[i] - b[p]) > x) continue;
    long long r =
        std::max((x + a[i] + b[p]) >> 1, b[p] + x - std::abs(a[i] - b[p]));
    p = std::upper_bound(b + p, b + m + 1, r) - b;
  }
  return p > m;
}
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= n; i++) Read(a[i]);
  for (int i = 1; i <= m; i++) Read(b[i]);
  long long l = 0LL, r = 1e11, best;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (Check(mid)) {
      best = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  std::printf("%lld", best);
  return 0;
}