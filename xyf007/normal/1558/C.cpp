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
int T, n, a[2025];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++)
    if ((i & 1) != (a[i] & 1)) {
      std::cout << "-1\n";
      return;
    }
  std::vector<int> v;
  for (int i = n; i >= 3; i -= 2) {
    int p = 1;
    for (int j = 1; j <= i; j++)
      if (a[j] == i) {
        p = j;
        break;
      }
    v.emplace_back(p);
    std::reverse(a + 1, a + p + 1);
    for (int j = 1; j <= i; j++)
      if (a[j] == i - 1) {
        p = j;
        break;
      }
    v.emplace_back(p - 1);
    std::reverse(a + 1, a + p);
    v.emplace_back(p + 1);
    std::reverse(a + 1, a + p + 2);
    v.emplace_back(3);
    std::reverse(a + 1, a + 4);
    v.emplace_back(i);
    std::reverse(a + 1, a + i + 1);
  }
  std::cout << v.size() << '\n';
  for (auto &&i : v) std::cout << i << ' ';
  std::cout << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}