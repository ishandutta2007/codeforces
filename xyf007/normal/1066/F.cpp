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
#include <utility>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Node {
  int x, y, id;
  Node(int x = 0, int y = 0, int id = 0) : x(x), y(y), id(id) {}
} a[200001];
int n, b[200001];
long long dp[200001][2], c[200001];
std::vector<Node> v[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++)
    std::cin >> a[i].x >> a[i].y, b[i] = a[i].id = std::max(a[i].x, a[i].y);
  std::sort(b + 1, b + n + 1);
  int nn = std::unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i].id = std::lower_bound(b + 1, b + nn + 1, a[i].id) - b;
    v[a[i].id].emplace_back(a[i]);
  }
  v[0].emplace_back(0, 0, 0);
  for (int i = 1; i <= nn; i++)
    std::sort(v[i].begin(), v[i].end(), [](const Node &lhs, const Node &rhs) {
      return lhs.x == rhs.x ? lhs.y > rhs.y : lhs.x < rhs.x;
    });
  auto calc = [](const Node &l, const Node &r) {
    return std::abs(l.x - r.x) + std::abs(l.y - r.y);
  };
  for (int i = 1; i <= nn; i++)
    for (std::size_t j = 0; j + 1 < v[i].size(); j++)
      c[i] += calc(v[i][j], v[i][j + 1]);
  dp[0][0] = dp[0][1] = 0;
  for (int i = 1; i <= nn; i++) {
    dp[i][0] = std::min(dp[i - 1][0] + calc(v[i - 1].front(), v[i].back()),
                        dp[i - 1][1] + calc(v[i - 1].back(), v[i].back())) +
               c[i];
    dp[i][1] = std::min(dp[i - 1][0] + calc(v[i - 1].front(), v[i].front()),
                        dp[i - 1][1] + calc(v[i - 1].back(), v[i].front())) +
               c[i];
  }
  std::cout << std::min(dp[nn][0], dp[nn][1]);
  return 0;
}