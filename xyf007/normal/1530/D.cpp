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
int t, n, a[200001], b[200001], pos[200001], cnt[200001];
bool vis[200001];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n);
    for (int i = 1; i <= n; i++) Read(a[i]), cnt[a[i]]++;
    std::vector<int> v;
    for (int i = 1; i <= n; i++)
      if (!cnt[i]) v.emplace_back(i);
    std::reverse(v.begin(), v.end());
    int ans = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[a[i]]) {
        vis[a[i]] = true;
        pos[a[i]] = i;
        b[i] = a[i];
        ans++;
      } else {
        b[i] = v.back();
        v.pop_back();
        if (b[i] == i) std::swap(b[i], b[pos[a[i]]]), pos[a[i]] = i;
      }
    std::printf("%d\n", ans);
    for (int i = 1; i <= n; i++) std::printf("%d%c", b[i], " \n"[i == n]);
    for (int i = 1; i <= n; i++) cnt[a[i]] = 0;
    std::memset(vis + 1, false, n);
  }
  return 0;
}