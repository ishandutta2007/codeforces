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
int T, n;
void Solve() {
  std::cin >> n;
  std::priority_queue<std::pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    q.emplace(x, i);
  }
  std::vector<std::pair<int, int>> ans;
  while (!q.empty()) {
    std::pair<int, int> x = q.top(), y;
    q.pop();
    y = q.top();
    q.pop();
    if (x.first && y.first) {
      ans.emplace_back(x.second, y.second);
      x.first--, y.first--;
      q.emplace(x), q.emplace(y);
    } else {
      break;
    }
  }
  std::cout << ans.size() << '\n';
  for (auto &&[x, y] : ans) std::cout << x << ' ' << y << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}