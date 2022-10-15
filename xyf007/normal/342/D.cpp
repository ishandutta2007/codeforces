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
int n, dp[10001][8];
char a[3][10001];
void Solve() {
  std::memset(dp, 0, sizeof(dp));
  dp[0][7] = 1;
  for (int i = 1; i <= n; i++) {
    int T = 0;
    for (int j = 0; j < 3; j++)
      if (a[j][i] != '.') T |= 1 << j;
    Add(dp[i][T], dp[i - 1][7]);
    if (!(T & 1)) Add(dp[i][T | 1], dp[i - 1][6]);
    if (!(T & 2)) Add(dp[i][T | 2], dp[i - 1][5]);
    if (!(T & 3)) Add(dp[i][T | 3], dp[i - 1][4], dp[i - 1][7]);
    if (!(T & 4)) Add(dp[i][T | 4], dp[i - 1][3]);
    if (!(T & 5)) Add(dp[i][T | 5], dp[i - 1][2]);
    if (!(T & 6)) Add(dp[i][T | 6], dp[i - 1][1], dp[i - 1][7]);
    if (!T) Add(dp[i][7], dp[i - 1][0], dp[i - 1][3], dp[i - 1][6]);
  }
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 0; i < 3; i++) std::scanf("%s", a[i] + 1);
  int x = 0, y = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j] == 'O') {
        x = i;
        y = j;
        break;
      }
  int ans = 0;
  for (int L = 0; L < 2; L++)
    for (int R = 0; R < 2; R++)
      for (int U = 0; U < 2; U++)
        for (int D = 0; D < 2; D++) {
          if ((L && (y <= 2 || a[x][y - 1] == 'X' || a[x][y - 2] == 'X')) ||
              (R && (y + 2 > n || a[x][y + 1] == 'X' || a[x][y + 2] == 'X')) ||
              (U && (x < 2 || a[x - 1][y] == 'X' || a[x - 2][y] == 'X')) ||
              (D && (x || a[x + 1][y] == 'X' || a[x + 2][y] == 'X')) ||
              !(L + R + U + D))
            continue;
          int op = (L + R + U + D) & 1;
          if (L) a[x][y - 1] = a[x][y - 2] = 'X';
          if (R) a[x][y + 1] = a[x][y + 2] = 'X';
          if (U) a[x - 1][y] = a[x - 2][y] = 'X';
          if (D) a[x + 1][y] = a[x + 2][y] = 'X';
          Solve();
          if (op & 1)
            Add(ans, dp[n][7]);
          else
            Sub(ans, dp[n][7]);
          if (L) a[x][y - 1] = a[x][y - 2] = '.';
          if (R) a[x][y + 1] = a[x][y + 2] = '.';
          if (U) a[x - 1][y] = a[x - 2][y] = '.';
          if (D) a[x + 1][y] = a[x + 2][y] = '.';
        }
  std::printf("%d", ans);
  return 0;
}