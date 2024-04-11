#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
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
int k, m, a[5], vis[20001], T;
std::set<int> Calc(int l, int r) {
  std::set<int> ans;
  if (l == r) {
    ans.emplace(a[l]);
    ans.emplace(-a[l]);
    return ans;
  }
  for (int i = l; i < r; i++) {
    std::set<int> s1 = Calc(l, i), s2 = Calc(i + 1, r);
    for (auto &&x : s1)
      for (auto &&y : s2) {
        ans.emplace(x + y);
        ans.emplace(x - y);
        ans.emplace(x * y);
      }
  }
  return ans;
}
void Dfs(int n) {
  if (n == 5) {
    std::set<int> s = Calc(1, 4);
    T++;
    for (auto &&i : s)
      if (int d = std::abs(i - k); d < 10000 && vis[d] != T) {
        vis[d] = T;
        std::printf("%04d%d%d%d%d\n", d, a[1], a[2], a[3], a[4]);
        if (!--m) std::exit(0);
      }
    return;
  }
  for (a[n] = 0; a[n] <= 9; a[n]++) Dfs(n + 1);
}
int main(int argc, char const *argv[]) {
  Read(k, m);
  Dfs(1);
  return 0;
}