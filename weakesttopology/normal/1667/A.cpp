#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<long long> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }
  long long ans = std::numeric_limits<long long>::max();
  for (int m = 0; m < N; ++m) {
    long long cost = 0;
    std::vector<long long> b(N);
    for (int i = m + 1; i < N; ++i) {
      long long k = b[i - 1] / a[i] + 1;
      b[i] = k * a[i];
      cost += k;
    }
    for (int i = m - 1; i >= 0; --i) {
      long long k = b[i + 1] / a[i] + 1;
      b[i] = k * a[i];
      cost += k;
    }
    ans = std::min(ans, cost);
  }
  std::cout << ans << '\n';
  exit(0);
}