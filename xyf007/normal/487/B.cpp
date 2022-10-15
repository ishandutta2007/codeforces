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
int n, l, s, a[100001], lg[100001], min[18][100001], max[18][100001],
    dp[100001];
int QueryMin(int l, int r) {
  int len = lg[r - l + 1];
  return std::min(min[len][l], min[len][r - (1 << len) + 1]);
}
int QueryMax(int l, int r) {
  int len = lg[r - l + 1];
  return std::max(max[len][l], max[len][r - (1 << len) + 1]);
}
int QueryDelta(int l, int r) { return QueryMax(l, r) - QueryMin(l, r); }
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> s >> l;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; i++) min[0][i] = max[0][i] = a[i];
  for (int j = 1; j <= lg[n]; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      min[j][i] = std::min(min[j - 1][i], min[j - 1][i + (1 << (j - 1))]);
      max[j][i] = std::max(max[j - 1][i], max[j - 1][i + (1 << (j - 1))]);
    }
  std::memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  int p = 0;
  for (int i = l; i <= n; i++) {
    while (p <= i - l && (QueryDelta(p + 1, i) > s || dp[p] == 0x3f3f3f3f)) p++;
    if (p <= i - l) dp[i] = dp[p] + 1;
  }
  if (dp[n] == 0x3f3f3f3f)
    std::cout << -1;
  else
    std::cout << dp[n];
  return 0;
}