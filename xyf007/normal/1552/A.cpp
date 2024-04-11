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
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = std::getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + (c - '0');
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
int t, n, a[1001], b[1001];
char s[1001];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n);
    std::scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) a[i] = s[i] - 'a';
    std::memcpy(b + 1, a + 1, 4 * n);
    std::sort(b + 1, b + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i] != b[i];
    std::printf("%d\n", ans);
  }
  return 0;
}