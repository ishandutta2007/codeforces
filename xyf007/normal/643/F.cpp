#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
unsigned int n, p, q, c[131];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> p >> q;
  c[0] = 1U;
  for (unsigned int i = 1; i <= p; i++) {
    std::vector<unsigned int> a(i), b(i);
    std::iota(a.begin(), a.end(), n - i + 1U);
    std::iota(b.begin(), b.end(), 1U);
    for (auto &&j : a) {
      for (auto &&k : b) {
        unsigned int gcd = std::__gcd(j, k);
        j /= gcd;
        k /= gcd;
      }
    }
    c[i] = 1U;
    for (auto &&j : a) {
      c[i] *= j;
    }
  }
  unsigned int ans = 0U;
  for (unsigned int i = 1; i <= q; i++) {
    unsigned int tmp = 0U, s = 1U;
    for (unsigned int j = 0; j <= p && j < n; j++) {
      tmp += c[j] * s;
      s *= i;
    }
    ans ^= i * tmp;
  }
  std::cout << ans;
  return 0;
}