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
int n, k, a[10001], pre[101];
bool vis[101];
std::pair<int, int> ans[101];
int main(int argc, char const *argv[]) {
  Read(n, k);
  for (int i = 1; i <= n * k; i++) Read(a[i]);
  for (int l = 1, r = k - 1; l <= n; l += k - 1, r += k - 1) {
    checkmin(r, n);
    for (int i = 1; i <= n * k; ++i)
      if (l <= a[i] && a[i] <= r && !vis[a[i]])
        if (pre[a[i]]) {
          ans[a[i]] = {pre[a[i]], i};
          vis[a[i]] = true;
          for (int j = l; j <= r; ++j) pre[j] = 0;
        } else {
          pre[a[i]] = i;
        }
  }
  for (int i = 1; i <= n; i++)
    std::printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}