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
int n, c, d, cnt[2], max[2][18][100001], lg[100001];
std::pair<int, int> a[2][100001];
int Query(int id, int l, int r) {
  int len = lg[r - l + 1];
  return std::max(max[id][len][l], max[id][len][r - (1 << len) + 1]);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> c >> d;
  for (int i = 1; i <= n; i++) {
    int val, cos;
    char s[10];
    std::cin >> val >> cos >> s;
    a[s[0] - 'C'][++cnt[s[0] - 'C']] = {cos, val};
  }
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  std::sort(a[0] + 1, a[0] + cnt[0] + 1);
  std::sort(a[1] + 1, a[1] + cnt[1] + 1);
  for (int i = 1; i <= cnt[0]; i++) max[0][0][i] = a[0][i].second;
  for (int i = 1; i <= cnt[1]; i++) max[1][0][i] = a[1][i].second;
  for (int j = 1; j <= lg[cnt[0]]; j++)
    for (int i = 1; i + (1 << j) - 1 <= cnt[0]; i++)
      max[0][j][i] =
          std::max(max[0][j - 1][i], max[0][j - 1][i + (1 << (j - 1))]);
  for (int j = 1; j <= lg[cnt[1]]; j++)
    for (int i = 1; i + (1 << j) - 1 <= cnt[1]; i++)
      max[1][j][i] =
          std::max(max[1][j - 1][i], max[1][j - 1][i + (1 << (j - 1))]);
  int ans = 0,
      p1 = std::lower_bound(a[0] + 1, a[0] + cnt[0] + 1,
                            std::make_pair(c + 1, 0)) -
           a[0] - 1,
      p2 = std::lower_bound(a[1] + 1, a[1] + cnt[1] + 1,
                            std::make_pair(d + 1, 0)) -
           a[1] - 1;
  if (p1 && p2) checkmax(ans, Query(0, 1, p1) + Query(1, 1, p2));
  for (int l = 1, r = cnt[0]; l < r; l++) {
    while (r > l && a[0][l].first + a[0][r].first > c) r--;
    if (l == r) break;
    checkmax(ans, a[0][l].second + Query(0, l + 1, r));
  }
  for (int l = 1, r = cnt[1]; l < r; l++) {
    while (r > l && a[1][l].first + a[1][r].first > d) r--;
    if (l == r) break;
    checkmax(ans, a[1][l].second + Query(1, l + 1, r));
  }
  std::cout << ans;
  return 0;
}