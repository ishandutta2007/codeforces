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
constexpr int kDx[] = {0, 1, 1, 1, 0, -1, -1, -1},
              kDy[] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, x0, y0, x1, y1;
std::set<std::pair<int, int>> vis, can;
std::map<std::pair<int, int>, int> dis;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> x0 >> y0 >> x1 >> y1 >> n;
  for (int i = 1; i <= n; i++) {
    int k, l, r;
    std::cin >> k >> l >> r;
    for (int j = l; j <= r; j++) can.emplace(k, j);
  }
  std::queue<std::pair<int, int>> q;
  q.emplace(x0, y0);
  vis.emplace(x0, y0);
  dis[{x0, y0}] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    int d = dis[{x, y}];
    for (int i = 0; i < 8; i++) {
      int tx = x + kDx[i], ty = y + kDy[i];
      if (!vis.count({tx, ty}) && can.count({tx, ty})) {
        q.emplace(tx, ty);
        vis.emplace(tx, ty);
        dis[{tx, ty}] = d + 1;
      }
    }
  }
  if (dis.count({x1, y1}))
    std::cout << dis[{x1, y1}];
  else
    std::cout << -1;
  return 0;
}