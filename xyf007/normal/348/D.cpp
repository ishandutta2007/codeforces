#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
constexpr int kMod = 1e9 + 7;
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
int n, m, dp[3001][3001];
char a[3001][3001];
int Calc(int x1, int y1, int x2, int y2) {
  if (a[x1][y1] == '#') return 0;
  std::memset(dp, 0, sizeof(dp));
  dp[x1][y1] = 1;
  for (int i = x1; i <= x2; i++)
    for (int j = y1 + (i == x1); j <= y2; j++)
      if (a[i][j] != '#') dp[i][j] = add(dp[i - 1][j], dp[i][j - 1]);
  return dp[x2][y2];
}
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= n; i++) std::scanf("%s", a[i] + 1);
  std::printf("%d", sub(mul(Calc(1, 2, n - 1, m), Calc(2, 1, n, m - 1)),
                        mul(Calc(1, 2, n, m - 1), Calc(2, 1, n - 1, m))));
  return 0;
}