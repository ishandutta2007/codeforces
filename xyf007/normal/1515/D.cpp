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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
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
int t, n, l, r, a[200001], b[200001], c[200001];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, l, r);
    for (int i = 1; i <= n; i++) Read(a[i]);
    std::multiset<int> s1, s2;
    for (int i = 1; i <= l; i++) s1.emplace(a[i]);
    for (int i = l + 1; i <= n; i++) s2.emplace(a[i]);
    for (int i = 1; i <= l; i++)
      if (s2.find(a[i]) != s2.end()) {
        s1.erase(s1.find(a[i]));
        s2.erase(s2.find(a[i]));
      }
    int tot1 = 0, tot2 = 0, cnt1 = 0, cnt2 = 0;
    for (auto &&i : s1) b[++tot1] = i;
    for (auto &&i : s2) c[++tot2] = i;
    for (int i = 1; i < tot1; i++)
      if (b[i] == b[i + 1]) {
        cnt1++;
        i++;
      }
    for (int i = 1; i < tot2; i++)
      if (c[i] == c[i + 1]) {
        cnt2++;
        i++;
      }
    int max = std::max(tot1 - 2 * cnt1, tot2 - 2 * cnt2), ans = 0;
    if (tot1 > max) ans += (tot1 - max) >> 1;
    if (tot2 > max) ans += (tot2 - max) >> 1;
    checkmin(tot1, max);
    checkmin(tot2, max);
    std::printf("%d\n", ans + std::max(tot1, tot2));
  }
  return 0;
}