#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <unordered_set>
size_t n, m, a[100001];
std::unordered_set<size_t> s[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (size_t i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 1; i <= m; i++) {
    size_t u, v;
    std::cin >> u >> v;
    if (a[u] != a[v]) {
      s[a[u]].emplace(a[v]);
      s[a[v]].emplace(a[u]);
    }
  }
  size_t max = 0, ans = 100001;
  for (size_t i = 1; i <= n; i++) {
    if (s[a[i]].size() > max) {
      max = s[a[i]].size();
      ans = a[i];
    } else if (s[a[i]].size() == max && a[i] < ans) {
      ans = a[i];
    }
  }
  std::cout << ans;
  return 0;
}