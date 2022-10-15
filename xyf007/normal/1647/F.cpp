#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <iostream>
constexpr int kB = 1 << 20;
char rbuf[kB + 1], *ps = rbuf + kB;
char Getchar() {
  if (ps - rbuf == kB) std::cin.read(rbuf, kB), ps = rbuf;
  return *ps++;
}
template <typename T = int>
T Read() {
  T x = 0;
  int f = 1;
  char c;
  while ((c = Getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  return x * f;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
void Read(char &c) { c = Getchar(); }
void Read(char *s) {
  char c = Getchar();
  while (c <= 32) c = Getchar();
  while (c > 32) *s++ = c, c = Getchar();
  *s = '\0';
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x), Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, a[500005], f[500005][2], g[500005][2];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  int pos = std::max_element(a + 1, a + n + 1) - a;
  for (int i = 1; i <= pos; i++) {
    f[i][0] = f[i][1] = 0x3f3f3f3f;
    if (a[i] > a[i - 1]) checkmin(f[i][0], f[i - 1][0]);
    if (a[i] > f[i - 1][1]) checkmin(f[i][0], a[i - 1]);
    if (a[i] > a[i - 1]) checkmin(f[i][1], f[i - 1][1]);
    if (a[i] > f[i - 1][0]) checkmin(f[i][1], a[i - 1]);
  }
  for (int i = pos + 1; i <= n; i++) {
    f[i][0] = 0x3f3f3f3f;
    if (a[i] < a[i - 1]) checkmin(f[i][0], f[i - 1][0]);
    if (a[i] < f[i - 1][1]) checkmin(f[i][0], a[i - 1]);
    if (a[i] > a[i - 1]) checkmax(f[i][1], f[i - 1][1]);
    if (a[i] > f[i - 1][0]) checkmax(f[i][1], a[i - 1]);
  }
  for (int i = n; i >= pos; i--) {
    g[i][0] = g[i][1] = 0x3f3f3f3f;
    if (a[i] > a[i + 1]) checkmin(g[i][0], g[i + 1][0]);
    if (a[i] > g[i + 1][1]) checkmin(g[i][0], a[i + 1]);
    if (a[i] > a[i + 1]) checkmin(g[i][1], g[i + 1][1]);
    if (a[i] > g[i + 1][0]) checkmin(g[i][1], a[i + 1]);
  }
  for (int i = pos - 1; i >= 1; i--) {
    g[i][0] = 0x3f3f3f3f;
    if (a[i] < a[i + 1]) checkmin(g[i][0], g[i + 1][0]);
    if (a[i] < g[i + 1][1]) checkmin(g[i][0], a[i + 1]);
    if (a[i] > a[i + 1]) checkmax(g[i][1], g[i + 1][1]);
    if (a[i] > g[i + 1][0]) checkmax(g[i][1], a[i + 1]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (i < pos)
      ans += f[i][1] < g[i][1];
    else if (i > pos)
      ans += f[i][1] > g[i][1];
  std::cout << ans;
  return 0;
}