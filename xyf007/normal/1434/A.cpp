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
int n, a[7], b[100001], tot, vis[100001];
std::pair<int, int> c[600001];
int main(int argc, char const *argv[]) {
  for (int i = 1; i <= 6; i++) Read(a[i]);
  Read(n);
  for (int i = 1; i <= n; i++) {
    Read(b[i]);
    for (int j = 1; j <= 6; j++) c[++tot] = {b[i] - a[j], i};
  }
  std::sort(c + 1, c + 6 * n + 1);
  int r = 0, ans = 0x7fffffff, cnt = 0;
  for (int i = 1; i <= 6 * n; i++) {
    while (cnt < n && r < 6 * n) {
      if (!vis[c[++r].second]) cnt++;
      vis[c[r].second]++;
    }
    if (cnt < n) break;
    checkmin(ans, c[r].first - c[i].first);
    if (!--vis[c[i].second]) cnt--;
  }
  std::printf("%d", ans);
  return 0;
}