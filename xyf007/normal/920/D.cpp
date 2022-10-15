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
int n, k, v, a[5001], pre[5001][5001];
bool dp[5001][5001], vis[5001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k >> v;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  dp[0][0] = true;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < k; j++)
      if (dp[i - 1][j]) {
        dp[i][j] = dp[i][(j + a[i]) % k] = true;
        pre[i][j] = pre[i][(j + a[i]) % k] = j;
      }
  if (!dp[n][v % k]) {
    std::cout << "NO";
    return 0;
  }
  std::vector<std::tuple<int, int, int>> ans;
  int now = v % k;
  for (int i = n; i >= 1; i--) {
    if (pre[i][now] != now) vis[i] = true;
    now = pre[i][now];
  }
  int fr0 = 0, fr1 = 0;
  for (int i = 1; i <= n; i++)
    if (vis[i]) {
      fr0 = i;
      break;
    }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      fr1 = i;
      break;
    }
  for (int i = 1; i <= n; i++)
    if (vis[i] && i != fr0)
      if (a[i]) {
        ans.emplace_back((a[i] + k - 1) / k, i, fr0), a[fr0] += a[i];
        a[i] = 0;
      }
  for (int i = 1; i <= n; i++)
    if (!vis[i] && i != fr1)
      if (a[i]) {
        ans.emplace_back((a[i] + k - 1) / k, i, fr1), a[fr1] += a[i];
        a[i] = 0;
      }
  if (!fr0) fr0 = 2, vis[2] = true;
  if (!fr1) fr1 = 2;
  if (a[fr0] + a[fr1] / k * k < v) {
    std::cout << "NO";
    return 0;
  }
  if (a[fr0] < v)
    ans.emplace_back((v - a[fr0]) / k, fr1, fr0);
  else if (a[fr0] > v)
    ans.emplace_back((a[fr0] - v) / k, fr0, fr1);
  std::cout << "YES\n";
  for (auto &&[c, x, y] : ans) std::cout << c << ' ' << x << ' ' << y << '\n';
  return 0;
}