#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
template <typename T = int>
T Read() {
  T x = 0;
  int f = 1;
  char c;
  while ((c = std::getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  return x * f;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = std::getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x), Read(args...);
}
template <typename T>
void Write(const T &x) {
  if (x < 0) {
    std::putchar('-'), Write(-x);
    return;
  }
  if (x > 9) Write(x / 10);
  std::putchar(x % 10 + '0');
}
template <typename T, typename... Args>
void Write(const T &x, const Args &...args) {
  Write(x), Write(args...);
}
int n, m, com, a[2][16384], fa[32768];
char s[4096];
int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) {
  x = Find(x), y = Find(y);
  if (x == y) return;
  com--, fa[x] = y;
}
int main(int argc, char const *argv[]) {
  Read(n, m);
  int l = m >> 2;
  for (int i = 1; i <= n; i++) {
    int cur = i & 1, pre = cur ^ 1;
    std::fread(s, 1, l, stdin), std::getchar();
    for (int j = 0; j < l; j++) {
      int x = std::isdigit(s[j]) ? s[j] - '0' : s[j] - 'A' + 10;
      a[cur][4 * j] = (x >> 3) & 1;
      a[cur][4 * j + 1] = (x >> 2) & 1;
      a[cur][4 * j + 2] = (x >> 1) & 1;
      a[cur][4 * j + 3] = x & 1;
    }
    com += std::accumulate(a[cur], a[cur] + m, 0);
    for (int j = 0; j < m; j++)
      if (a[cur][j]) fa[cur * m + j] = cur * m + j;
    auto c = a[cur], p = a[pre];
    for (int j = 0; j < m; j++, p++, c++)
      if (*p && *c) Merge(pre * m + j, cur * m + j);
    for (int j = 0; j + 1 < m; j++)
      if (a[cur][j] && a[cur][j + 1]) Merge(cur * m + j, cur * m + j + 1);
  }
  Write(com);
  return 0;
}