#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, q;
long long a[100001], sum[100001], ans[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a + 1, a + n + 1);
  std::partial_sum(a + 1, a + n + 1, sum + 1);
  for (int i = 1; i < n; i++) {
    long long k = i, p = n - 1;
    while (p > 0) {
      ans[i] += sum[p];
      p -= k;
      k *= i;
    }
  }
  std::cin >> q;
  int x;
  while (q--) {
    std::cin >> x;
    std::cout << ans[std::min(x, n - 1)] << ' ';
  }
  return 0;
}