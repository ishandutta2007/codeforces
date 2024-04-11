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
int n, q, lg[100001];
long long a[100001], b[100001], sa[100001], sb[100001], min[18][100001],
    max[18][100001];
long long QueryMax(int l, int r) {
  int len = lg[r - l + 1];
  return std::max(max[len][l], max[len][r - (1 << len) + 1]);
}
long long QueryMin(int l, int r) {
  int len = lg[r - l + 1];
  return std::min(min[len][l], min[len][r - (1 << len) + 1]);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) std::cin >> b[i];
  std::partial_sum(a + 1, a + n + 1, sa + 1);
  std::partial_sum(b + 1, b + n + 1, sb + 1);
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; i++) max[0][i] = min[0][i] = sb[i] - sa[i];
  for (int j = 1; j <= lg[n]; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      max[j][i] = std::max(max[j - 1][i], max[j - 1][i + (1 << (j - 1))]);
      min[j][i] = std::min(min[j - 1][i], min[j - 1][i + (1 << (j - 1))]);
    }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (sa[r] - sa[l - 1] != sb[r] - sb[l - 1]) {
      std::cout << "-1\n";
      continue;
    }
    long long mx = QueryMax(l, r), mn = QueryMin(l, r);
    mx -= sb[l - 1] - sa[l - 1], mn -= sb[l - 1] - sa[l - 1];
    if (mn < 0)
      std::cout << "-1\n";
    else
      std::cout << mx << '\n';
  }
  return 0;
}