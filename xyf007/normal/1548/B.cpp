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
int T, n;
long long a[200001], b[200001], g[200001][19];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i < n; i++) b[i] = std::abs(a[i + 1] - a[i]);
  for (int i = 1; i < n; i++) g[i][0] = b[i];
  n--;
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      g[i][j] = std::__gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int p = i;
    long long gcd = 0LL;
    for (int j = 18; j >= 0; j--) {
      if (p + (1 << j) - 1 > n) continue;
      if (long long G = std::__gcd(gcd, g[p][j]); G > 1 || !G)
        p += 1 << j, gcd = G;
    }
    checkmax(ans, p - i);
  }
  std::cout << ans + 1 << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}