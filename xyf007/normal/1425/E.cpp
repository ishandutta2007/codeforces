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
int n, k;
long long a[100001], d[100001], suf[100005], f[100001], pf[100001], sf[100005],
    cyc[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) std::cin >> d[i];
  if (k > 1) {
    std::cout << std::max({0LL,
                           std::accumulate(a + 1, a + n + 1, 0LL) -
                               *std::min_element(d + 1, d + n),
                           a[n] - d[n]});
    return 0;
  }
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
  for (int i = 1; i <= n; i++) f[i] = suf[i] - d[i];
  for (int i = 1; i <= n; i++) pf[i] = std::max(pf[i - 1], f[i]);
  for (int i = n; i >= 1; i--) sf[i] = std::max(sf[i + 1], f[i]);
  if (!k) {
    std::cout << pf[n];
    return 0;
  }
  long long sum = a[1], min = d[1];
  for (int i = 2; i < n; i++) {
    sum += a[i], checkmin(min, d[i]);
    cyc[i] = std::max(0LL, sum - min);
  }
  long long ans = 0LL;
  for (int i = 2; i < n; i++) checkmax(ans, cyc[i] + sf[i + 1]);
  for (int i = 1; i <= n - 2; i++)
    checkmax(ans, std::max(sf[i + 1], std::max(pf[i] - a[i + 1], 0LL) +
                                          std::max(a[i + 1] - d[i + 1], 0LL)));
  std::cout << ans;
  return 0;
}