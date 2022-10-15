#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <unordered_set>
int n, k, a[51];
std::unordered_set<int> s;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::srand(std::time(nullptr));
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a + 1, a + n + 1, std::greater<int>());
  for (int i = 0; i < n && k; i++) {
    for (int j = i + 1; j <= n && k; j++) {
      std::cout << i + 1 << ' ';
      for (int l = 1; l <= i; l++) {
        std::cout << a[l] << ' ';
      }
      std::cout << a[j] << '\n';
      k--;
    }
  }
  return 0;
}