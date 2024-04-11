#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
int t, n, k;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> n >> k;
    int p = (k + 1) / 2;
    std::vector<int> v;
    for (int i = p; i <= n; i++) {
      if (i != k) {
        v.emplace_back(i);
      }
    }
    std::cout << v.size() << '\n';
    for (auto &&i : v) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}