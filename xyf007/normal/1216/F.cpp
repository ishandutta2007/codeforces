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
int n, k, po[200005];
long long dp[200001];
std::string s;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k >> s, s = ' ' + s;
  po[n + 1] = 0x3f3f3f3f;
  for (int i = n; i >= 1; i--) po[i] = s[i] == '1' ? i : po[i + 1];
  std::memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0LL;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + i;
    int pre = po[std::max(i - k, 1)];
    if (pre <= i + k) checkmin(dp[i], dp[std::max(pre - k, 1) - 1] + pre);
  }
  std::cout << dp[n];
  return 0;
}