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
int n, d, k, now;
std::vector<std::pair<int, int>> ans;
void Dfs(int u, int lim) {
  if (u == n) {
    std::cout << "YES\n";
    for (auto &&[u, v] : ans) std::cout << u << ' ' << v << '\n';
    std::exit(0);
  }
  if (!lim) return;
  for (int i = 1; i < k; i++) {
    ans.emplace_back(u, ++now);
    Dfs(now, lim - 1);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> d >> k;
  if (k == 1) {
    if (n == 2 && d == 1)
      std::cout << "YES\n"
                << "1 2";
    else
      std::cout << "NO";
    return 0;
  }
  if (n <= d) {
    std::cout << "NO";
    return 0;
  }
  for (int i = 1; i <= d; i++) ans.emplace_back(i, i + 1);
  if (n == d + 1) {
    std::cout << "YES\n";
    for (auto &&[u, v] : ans) std::cout << u << ' ' << v << '\n';
    return 0;
  }
  now = d + 1;
  for (int i = 2; i <= d; i++)
    for (int j = 1; j <= k - 2; j++) {
      ans.emplace_back(i, ++now);
      Dfs(now, d - 1 - std::max(i - 1, d + 1 - i));
    }
  std::cout << "NO";
  return 0;
}