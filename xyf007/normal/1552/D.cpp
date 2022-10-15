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
int t, n, a[11], s[1024];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n);
    int full = (1 << n) - 1;
    std::memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i++) Read(a[i]), a[i] = std::abs(a[i]);
    for (int S = 0; S <= full; S++)
      for (int i = 0; i < n; i++)
        if ((S >> i) & 1) s[S] += a[i];
    bool f = false;
    for (int S = 0; S <= full; S++) {
      int rS = S ^ full;
      for (int T = rS; T; T = (T - 1) & rS)
        if (s[S] == s[T]) {
          f = true;
          break;
        }
      if (f) break;
    }
    if (f)
      std::printf("YES\n");
    else
      std::printf("NO\n");
  }
  return 0;
}