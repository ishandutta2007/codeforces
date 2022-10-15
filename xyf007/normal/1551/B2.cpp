#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
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
int t, n, k, a[200001], b[200001], ans[200001];
std::vector<int> p[200001];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, k);
    for (int i = 1; i <= n; i++) Read(a[i]), p[a[i]].emplace_back(i);
    std::iota(b + 1, b + n + 1, 1);
    std::sort(b + 1, b + n + 1, [](const int &lhs, const int &rhs) {
      return p[lhs].size() > p[rhs].size();
    });
    std::vector<int> p2;
    for (int i = 1; i <= n; i++)
      if (static_cast<int>(p[b[i]].size()) >= k)
        for (int j = 0; j < k; j++) ans[p[b[i]][j]] = j + 1;
      else
        p2.insert(p2.end(), p[b[i]].begin(), p[b[i]].end());
    int tot = p2.size() / k;
    for (int i = 0; i < tot; i++)
      for (int j = i * k; j < (i + 1) * k; j++) ans[p2[j]] = j % k + 1;
    for (int i = 1; i <= n; i++) std::printf("%d%c", ans[i], " \n"[i == n]);
    for (int i = 1; i <= n; i++) p[a[i]].pop_back();
    std::memset(ans + 1, 0, 4 * n);
  }
  return 0;
}