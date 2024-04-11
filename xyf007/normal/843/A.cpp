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
int n, a[100001], b[100001];
std::vector<std::vector<int>> ans;
bool vis[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::memcpy(b + 1, a + 1, 4 * n);
  std::sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++)
    a[i] = std::lower_bound(b + 1, b + n + 1, a[i]) - b;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      ans.emplace_back(std::vector<int>());
      vis[i] = true;
      std::vector<int> &v = ans.back();
      v.emplace_back(i);
      for (int j = a[i]; j != i; j = a[j]) {
        vis[j] = true;
        v.emplace_back(j);
      }
    }
  std::cout << ans.size() << '\n';
  for (auto &&v : ans) {
    std::cout << v.size();
    for (auto &&i : v) std::cout << ' ' << i;
    std::cout << '\n';
  }
  return 0;
}