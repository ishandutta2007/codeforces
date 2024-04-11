#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
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
int n, m, a[1001][1001];
bool vis[1001][1001];
bool Check(int x) {
  std::memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    std::vector<int> v;
    for (int j = 1; j <= m; j++)
      if (a[i][j] >= x) v.emplace_back(j);
    for (std::size_t j = 0; j + 1 < v.size(); j++)
      for (std::size_t k = j + 1; k < v.size(); k++)
        if (vis[v[j]][v[k]])
          return true;
        else
          vis[v[j]][v[k]] = true;
  }
  return false;
}
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) Read(a[i][j]);
  int l = 0, r = 1e9, best = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (Check(mid)) {
      best = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  std::printf("%d", best);
  return 0;
}