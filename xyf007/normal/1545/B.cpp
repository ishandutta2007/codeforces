#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int kMod = 998244353;
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = std::getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + (c - '0');
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
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
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
int t, n, fac[100001], inv[100001];
char s[100001];
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
  fac[0] = 1;
  for (int i = 1; i <= 100000; i++) fac[i] = mul(fac[i - 1], i);
  inv[100000] = Ksm(fac[100000], kMod - 2);
  for (int i = 99999; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
  Read(t);
  while (t--) {
    Read(n);
    std::scanf("%s", s + 1);
    int tot = std::count(s + 1, s + n + 1, '1'), cnt = 0, od = 0;
    for (int i = 1; i <= n; i++)
      if (s[i] == '1') {
        cnt++;
      } else {
        od += cnt & 1;
        cnt = 0;
      }
    od += cnt & 1;
    n -= od;
    tot -= od;
    tot >>= 1;
    std::printf("%d\n", C(n - tot, tot));
  }
  return 0;
}