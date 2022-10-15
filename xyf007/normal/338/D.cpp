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
__int128_t n, m, a[10001], b[10001];
int k;
__int128_t Exgcd(__int128_t a, __int128_t b, __int128_t &x, __int128_t &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  __int128_t gcd = Exgcd(b, a % b, x, y), tmp = x;
  x = y;
  y = tmp - a / b * y;
  return gcd;
}
int main(int argc, char const *argv[]) {
  Read(n, m, k);
  for (int i = 1; i <= k; i++) {
    Read(a[i]);
    b[i] = ((1 - i) % a[i] + a[i]) % a[i];
  }
  __int128_t lcm = a[1];
  for (int i = 2; i <= k; i++) {
    lcm = lcm / std::__gcd(lcm, a[i]) * a[i];
    if (lcm > n) {
      std::printf("NO");
      return 0;
    }
  }
  __int128_t ans = b[1], M = a[1], x, y;
  for (int i = 2; i <= k; i++) {
    __int128_t c = ((b[i] - ans) % a[i] + a[i]) % a[i],
               gcd = Exgcd(M, a[i], x, y), t = a[i] / gcd;
    if (c % gcd) {
      std::printf("NO");
      return 0;
    }
    x = x * c / gcd % t;
    ans += x * M;
    M *= t;
    ans = (ans % M + M) % M;
  }
  if (!ans) ans = M;
  if (ans + k - 1 > m) {
    std::printf("NO");
    return 0;
  }
  for (int i = 1; i <= k; i++)
    if (std::__gcd(lcm, ans + i - 1) != a[i]) {
      std::printf("NO");
      return 0;
    }
  std::printf("YES");
  return 0;
}