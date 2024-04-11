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
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  for (auto &&x : v) out << x << ' ';
  return out;
}
int T, n, a[501], c[501];
std::pair<int, int> b[501];
std::pair<std::vector<int>, bool> Check() {
  std::vector<int> v;
  for (int i = 1; i <= n - 2; i++) {
    int p = -1;
    for (int j = i; j <= n; j++)
      if (c[j] == i) {
        p = j;
        break;
      }
    if (p == i) continue;
    while (p - i >= 2)
      v.emplace_back(p - 2), std::rotate(c + p - 2, c + p, c + p + 1), p -= 2;
    if (p - i == 1) {
      v.emplace_back(i), std::rotate(c + i, c + i + 2, c + i + 3);
      v.emplace_back(i), std::rotate(c + i, c + i + 2, c + i + 3);
    }
  }
  return {v, c[n - 1] < c[n]};
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) b[i] = {a[i], i};
  std::sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) c[b[i].second] = i;
  auto res = Check();
  if (res.second) {
    std::cout << res.first.size() << '\n' << res.first << '\n';
    return;
  }
  for (int i = 1; i < n; i++)
    if (b[i].first == b[i + 1].first) {
      std::swap(b[i], b[i + 1]);
      break;
    }
  for (int i = 1; i <= n; i++) c[b[i].second] = i;
  res = Check();
  if (res.second) {
    std::cout << res.first.size() << '\n' << res.first << '\n';
    return;
  }
  std::cout << "-1\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}