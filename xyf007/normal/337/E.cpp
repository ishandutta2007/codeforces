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
int n, d[10], tot;
long long a[10];
std::vector<long long> tree;
int Dfs(int now, int ai_with_roots, int cnt) {
  if (!now) return n + (ai_with_roots > 1) + cnt - tot;
  int res = 0x3f3f3f3f;
  for (std::size_t i = 0; i < tree.size(); i++)
    if (!(tree[i] % a[now])) {
      tree[i] /= a[now];
      tree.emplace_back(a[now]);
      checkmin(res, Dfs(now - 1, ai_with_roots + !i, cnt + (!i ? d[now] : 0)));
      tree[i] *= a[now];
      tree.pop_back();
    }
  return res;
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  std::sort(a + 1, a + n + 1);
  for (int i = n; i > 0; i--) {
    long long tmp = a[i];
    for (long long j = 2; j * j <= tmp; j++)
      while (!(tmp % j)) {
        tmp /= j;
        d[i]++;
      }
    if (tmp > 1) d[i]++;
    if (d[i] == 1) tot++;
  }
  tree.emplace_back(0);
  std::printf("%d\n", Dfs(n, 0, 0));
  return 0;
}