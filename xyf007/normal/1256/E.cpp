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
int n, pre[200001], ans[200001];
std::pair<long long, int> a[200001];
long long dp[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i].first, a[i].second = i;
  std::sort(a + 1, a + n + 1);
  dp[0] = 0LL, dp[1] = dp[2] = 0x3f3f3f3f3f3f3f3fLL;
  long long min = -a[1].first, p = 0;
  for (int i = 3; i <= n; i++) {
    dp[i] = min + a[i].first, pre[i] = p;
    if (dp[i - 2] - a[i - 1].first < min)
      min = dp[i - 2] - a[i - 1].first, p = i - 2;
  }
  int cnt = 0;
  for (int i = n; i; i = pre[i]) cnt++;
  std::cout << dp[n] << ' ' << cnt << '\n';
  for (int i = n, pr = pre[i]; i; i = pr, pr = pre[pr]) {
    for (int j = pr + 1; j <= i; j++) ans[a[j].second] = cnt;
    cnt--;
  }
  for (int i = 1; i <= n; i++) std::cout << ans[i] << ' ';
  return 0;
}