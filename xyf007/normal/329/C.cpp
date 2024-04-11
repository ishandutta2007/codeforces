#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>
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
std::size_t n, m, a[100001];
std::set<std::pair<std::size_t, std::size_t>> s;
std::vector<std::pair<std::size_t, std::size_t>> ans;
std::mt19937 mt_rand(
    std::chrono::_V2::steady_clock::now().time_since_epoch().count());
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (std::size_t i = 1; i <= m; i++) {
    std::size_t u, v;
    Read(u, v);
    s.emplace(std::min(u, v), std::max(u, v));
  }
  std::size_t t = 3000000 / m;
  std::iota(a + 1, a + n + 1, 1);
  while (t--) {
    std::vector<std::pair<std::size_t, std::size_t>>().swap(ans);
    std::shuffle(a + 1, a + n + 1, mt_rand);
    a[0] = a[n];
    for (std::size_t i = 0; i < n; i++)
      if (!s.count({std::min(a[i], a[i + 1]), std::max(a[i], a[i + 1])}))
        ans.emplace_back(a[i], a[i + 1]);
    if (ans.size() < m) continue;
    for (std::size_t i = 0; i < m; i++)
      std::printf("%u %u\n", ans[i].first, ans[i].second);
    return 0;
  }
  std::printf("-1");
  return 0;
}