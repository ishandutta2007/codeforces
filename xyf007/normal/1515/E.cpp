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
int n, mod, fac[100001], inv[100001], dp[401][401], pw[100001];
template <typename T>
T add(T a, T b) {
  return (a + b) % mod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + mod - b) % mod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % mod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
int Ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int C(int x, int y) {
  if (x < y || y < 0) return 0;
  return mul(fac[x], inv[x - y], inv[y]);
}
int main(int argc, char const *argv[]) {
  Read(n, mod);
  fac[0] = pw[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    fac[i] = mul(fac[i - 1], i);
    pw[i] = add(pw[i - 1], pw[i - 1]);
  }
  inv[100000] = Ksm(fac[100000], mod - 2);
  for (int i = 99999; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
  dp[1][1] = pw[0];
  dp[2][1] = pw[1];
  for (int i = 3; i <= n; i++) {
    dp[i][1] = pw[i - 1];
    for (int j = 2; j <= (i + 1) / 2; j++)
      for (int k = 1; k <= i - 2; k++)
        Add(dp[i][j],
            mul(dp[k][j - 1], C(i - j + 1, i - k - 1), pw[i - k - 2]));
  }
  std::printf("%d", std::accumulate(dp[n] + 1, dp[n] + (n + 3) / 2, 0,
                                    [](const int &lhs, const int &rhs) -> int {
                                      return add(lhs, rhs);
                                    }));
  return 0;
}