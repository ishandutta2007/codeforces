#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
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
int t, n, m, a[300001], pos[300001], b[300001];
std::map<int, int> mp;
bool v[300001];
bool Check(int x) {
  int tot = 0;
  for (int i = 1; i <= n; i++) b[i] = a[(i + x - 1) % n + 1], v[i] = 0;
  for (int i = 1; i <= n; i++) tot += b[i] != i;
  for (int i = 1; i <= n; i++)
    if (b[i] != i && !v[i]) {
      v[i] = 1, tot--;
      int j = b[i];
      while (j != i) v[j] = 1, j = b[j];
    }
  return tot <= m;
}
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, m);
    for (int i = 1; i <= n; i++) Read(a[i]), pos[a[i]] = i;
    for (int i = 1; i <= n; i++) mp[(pos[i] - i + n) % n]++;
    std::vector<int> ans;
    for (int i = 0; i < n; i++)
      if (n - mp[i] <= 2 * m && Check(i)) ans.emplace_back(i);
    std::printf("%d", static_cast<int>(ans.size()));
    for (auto &&i : ans) std::printf(" %d", i);
    std::printf("\n");
    std::map<int, int>().swap(mp);
  }
  return 0;
}