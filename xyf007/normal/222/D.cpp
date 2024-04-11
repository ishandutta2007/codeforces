#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, x, a[100001], b[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::cout << "1 ";
  std::sort(a + 1, a + n + 1, std::greater<int>());
  std::sort(b + 1, b + n + 1);
  int p = 1, ans = 0;
  for (int i = 1; i <= n && p <= n; i++) {
    while (p < n && a[i] + b[p] < x) {
      p++;
    }
    if (a[i] + b[p] < x) {
      break;
    }
    ans++;
    p++;
  }
  std::cout << ans;
  return 0;
}