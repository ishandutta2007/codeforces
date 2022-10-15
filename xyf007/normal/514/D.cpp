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
int n, m, k, a[100001][5], lg[100001], max[18][100001][5];
std::vector<int> Query(int l, int r) {
  int len = lg[r - l + 1];
  std::vector<int> ans;
  for (int i = 0; i < m; i++)
    ans.emplace_back(std::max(max[len][l][i], max[len][r - (1 << len) + 1][i]));
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++) std::cin >> a[i][j];
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; i++)
    for (int c = 0; c < m; c++) max[0][i][c] = a[i][c];
  for (int j = 1; j <= lg[n]; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      for (int c = 0; c < m; c++)
        max[j][i][c] =
            std::max(max[j - 1][i][c], max[j - 1][i + (1 << (j - 1))][c]);
  int ans = 0;
  std::vector<int> sol(m);
  for (int i = 1; i <= n; i++) {
    int l = 1, r = i, best = i + 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      std::vector<int> res = Query(mid, i);
      if (std::accumulate(res.begin(), res.end(), 0) <= k) {
        best = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (i - best + 1 > ans) ans = i - best + 1, sol = Query(best, i);
  }
  for (auto &&i : sol) std::cout << i << ' ';
  return 0;
}