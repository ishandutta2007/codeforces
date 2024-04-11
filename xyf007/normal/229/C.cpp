#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, m, deg[1000001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    deg[u]++;
    deg[v]++;
  }
  long long ans = static_cast<long long>(n) * (n - 1) * (n - 2) / 6 -
                  static_cast<long long>(n - 2) * m;
  for (int i = 1; i <= n; i++) {
    ans += deg[i] * static_cast<long long>(deg[i] - 1) / 2;
  }
  std::cout << ans;
  return 0;
}