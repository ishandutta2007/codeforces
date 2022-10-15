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
int n, m, sz[4001];
long long a[4001], dp[4001][4001];
int Solve(int l, int r) {
  if (l > r) return 0;
  int p = std::min_element(a + l, a + r + 1) - a, u = Solve(l, p - 1),
      v = Solve(p + 1, r);
  sz[p] = sz[u] + sz[v] + 1;
  for (int i = 0; i <= sz[u]; i++)
    for (int j = 0; j <= sz[v]; j++) {
      checkmax(dp[p][i + j], dp[u][i] + dp[v][j] - 2 * a[p] * i * j);
      checkmax(dp[p][i + j + 1], dp[u][i] + dp[v][j] + a[p] * (m - 1) -
                                     2 * a[p] * (i * j + i + j));
    }
  return p;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::memset(dp, 0xcf, sizeof(dp));
  dp[0][0] = 0LL;
  std::cout << dp[Solve(1, n)][m];
  return 0;
}