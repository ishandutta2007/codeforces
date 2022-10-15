#include <algorithm>
#include <chrono>
#include <cstring>
#include <iostream>
#include <numeric>
#include <unordered_map>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct MyHash {
  static std::uint64_t splitmix64(std::uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  std::size_t operator()(std::uint64_t x) const {
    static const std::chrono::_V2::steady_clock::rep FIXED_RANDOM =
        std::chrono::_V2::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
int n, pre[3][300001];
long long a[2][300001], s[3][300001];
std::unordered_map<int, int> dp[300001];
int Dfs(int x, int y) {
  if (x < 0 || y < 0) return -0x3f3f3f3f;
  if (x == 0 && y == 0) return 0;
  if (dp[x].count(y)) return dp[x][y];
  int &ans = dp[x][y];
  if (pre[0][x] > pre[1][y])
    checkmax(ans, Dfs(pre[0][x], y) + 1);
  else
    checkmax(ans, Dfs(x, pre[1][y]) + 1);
  checkmax(ans, Dfs(pre[2][std::min(x, y)], pre[2][std::min(x, y)]) + 1);
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[0][i];
  for (int i = 1; i <= n; i++) std::cin >> a[1][i];
  std::partial_sum(a[0] + 1, a[0] + n + 1, s[0] + 1);
  std::partial_sum(a[1] + 1, a[1] + n + 1, s[1] + 1);
  for (int i = 1; i <= n; i++) s[2][i] = s[0][i] + s[1][i];
  std::unordered_map<long long, int, MyHash> mp[3];
  mp[0][0LL] = 0, mp[1][0LL] = 0, mp[2][0LL] = 0;
  pre[0][0] = pre[1][0] = pre[2][0] = -1;
  for (int i = 1; i <= n; i++) {
    pre[0][i] = mp[0].count(s[0][i]) ? mp[0][s[0][i]] : -1;
    pre[1][i] = mp[1].count(s[1][i]) ? mp[1][s[1][i]] : -1;
    pre[2][i] = mp[2].count(s[2][i]) ? mp[2][s[2][i]] : -1;
    checkmax(pre[0][i], pre[0][i - 1]);
    checkmax(pre[1][i], pre[1][i - 1]);
    checkmax(pre[2][i], pre[2][i - 1]);
    mp[0][s[0][i]] = mp[1][s[1][i]] = mp[2][s[2][i]] = i;
  }
  std::cout << Dfs(n, n);
  return 0;
}