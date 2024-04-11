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
int T, n, m, a[405][405], sum[405][405], k[405];
char s[405][405];
int Query(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> (s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = s[i][j] - '0';
  std::memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
  int ans = 0x3f3f3f3f;
  for (int l = 1; l + 3 <= m; l++)
    for (int r = l + 3; r <= m; r++) {
      k[n - 3] = r - l - 1 - Query(n, l + 1, n, r - 1) +
                 Query(n - 3, l + 1, n - 1, r - 1) + n - (n - 3) -
                 Query(n - 3, l, n - 1, l) + n - (n - 3) -
                 Query(n - 3, r, n - 1, r);
      for (int i = n - 4; i >= 1; i--) {
        k[i] = r - l - 1 - Query(i + 3, l + 1, i + 3, r - 1) +
               Query(i, l + 1, i + 2, r - 1) + 3 - Query(i, l, i + 2, l) + 3 -
               Query(i, r, i + 2, r);
        checkmin(k[i],
                 k[i + 1] + !a[i][l] + !a[i][r] + Query(i, l + 1, i, r - 1));
      }
      for (int i = 1; i <= n - 4; i++)
        checkmin(ans, k[i + 1] + r - l - 1 - Query(i, l + 1, i, r - 1));
    }
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}