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
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, a[1000001], g[1048576];
char s[1000005];
bool f[1048576];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> (s + 1), n = std::strlen(s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - 'a';
  f[0] = true;
  for (int i = 1; i <= n; i++) {
    int S = 0;
    for (int j = i; j <= n; j++) {
      if ((S >> a[j]) & 1) break;
      S |= 1 << a[j], f[S] = true;
    }
  }
  for (int S = 0; S < (1 << 20); S++)
    if (f[S]) g[S] = __builtin_popcount(S);
  for (int i = 0; i < 20; i++)
    for (int S = 0; S < (1 << 20); S++)
      if ((S >> i) & 1) checkmax(g[S], g[S ^ (1 << i)]);
  int ans = 0, full = (1 << 20) - 1;
  for (int S = 0; S < (1 << 20); S++)
    if (f[S]) checkmax(ans, __builtin_popcount(S) + g[S ^ full]);
  std::cout << ans;
  return 0;
}