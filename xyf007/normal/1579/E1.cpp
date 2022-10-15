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
int T, n, a[200001], pos[200001], cur;
std::vector<int> ans;
void Solve(int r) {
  while (cur <= n && pos[cur] > r) cur++;
  if (cur > n) return;
  int now = cur;
  ans.emplace_back(cur++);
  Solve(pos[now] - 1);
  for (int i = pos[now] + 1; i <= r; i++) ans.emplace_back(a[i]);
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i], pos[a[i]] = i;
  ans.clear();
  cur = 1;
  Solve(n);
  for (auto &&x : ans) std::cout << x << ' ';
  std::cout << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}