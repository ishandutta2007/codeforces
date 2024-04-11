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
int t, n, a[50001][6];
int Cmp(int i, int j) {
  int ans = 0;
  for (int k = 1; k <= 5; k++) ans += a[i][k] < a[j][k];
  return ans >= 3 ? i : j;
}
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= 5; j++) Read(a[i][j]);
    int p = 1;
    for (int i = 2; i <= n; i++) p = Cmp(p, i);
    bool f = true;
    for (int i = 1; i <= n; i++)
      if (Cmp(p, i) != p) {
        std::printf("-1\n");
        f = false;
        break;
      }
    if (f) std::printf("%d\n", p);
  }
  return 0;
}