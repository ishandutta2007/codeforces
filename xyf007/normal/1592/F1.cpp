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
int n, m, a[505][505], sum[505][505];
char s[505][505];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> (s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = s[i][j] == 'B';
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      ans += sum[i][j] =
          (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1]) & 1;
  bool f = false;
  for (int i = 1; i <= n && !f; i++)
    for (int j = 1; j <= m && !f; j++)
      if (sum[i - 1][j - 1] && sum[n][j - 1] && sum[i - 1][m] && sum[n][m])
        f = true;
  std::cout << ans - f;
  return 0;
}