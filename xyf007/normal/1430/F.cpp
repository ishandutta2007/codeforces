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
int n, k, a[2001], l[2001], r[2001], dp[2001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> l[i] >> r[i] >> a[i];
  for (int i = n; i >= 1; i--) {
    int cnt = a[i];
    if (i < n && r[i] == l[i + 1]) cnt += dp[i + 1];
    if ((cnt + k - 1) / k > r[i] - l[i] + 1) {
      std::cout << -1;
      return 0;
    }
    if ((cnt - 1) / k == r[i] - l[i]) dp[i] = cnt - k * (r[i] - l[i]);
  }
  long long ans = 0LL;
  int now = k;
  for (int i = 1; i <= n; i++) {
    if (now < dp[i]) ans += now, now = k;
    ans += a[i], now = ((now - a[i] % k) + k) % k;
  }
  std::cout << ans;
  return 0;
}