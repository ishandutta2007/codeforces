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
int t, n, k;
bool vis[1001];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, k);
    std::vector<std::pair<int, int>> a(k);
    std::memset(vis, false, sizeof(vis));
    for (int i = 0; i < k; i++) {
      Read(a[i].first, a[i].second);
      vis[a[i].first] = vis[a[i].second] = true;
    }
    std::vector<int> p;
    for (int i = 1; i <= 2 * n; i++)
      if (!vis[i]) p.emplace_back(i);
    for (int i = 0; i < n - k; i++) a.emplace_back(p[i], p[i + n - k]);
    for (int i = 0; i < n; i++)
      if ((a[i].first > a[i].second && a[i].first - a[i].second <= n) ||
          (a[i].first < a[i].second && a[i].second - a[i].first > n))
        std::swap(a[i].first, a[i].second);
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++) {
        auto [l1, r1] = a[i];
        auto [l2, r2] = a[j];
        if (l1 < r1)
          ans += ((l1 < l2 && l2 < r1) && !(l1 < r2 && r2 < r1)) ||
                 ((l1 < r2 && r2 < r1) && !(l1 < l2 && l2 < r1));
        else
          ans += ((l2 > l1 || l2 < r1) && !(r2 > l1 || r2 < r1)) ||
                 ((r2 > l1 || r2 < r1) && !(l2 > l1 || l2 < r1));
      }
    std::printf("%d\n", ans);
  }
  return 0;
}