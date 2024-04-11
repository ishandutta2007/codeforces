#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> a[i];
    }
    auto prefmax = a;
    for (int i = 0; i + 1 < N; ++i) {
      prefmax[i + 1] = std::max(a[i + 1], prefmax[i]);
    }
    int suffmin = a[N - 1];
    bool good = true;
    for (int i = N - 1; i > 0; --i) {
      suffmin = std::min(suffmin, a[i]);
      if (suffmin < prefmax[i - 1]) {
        good = false;
        break;
      }
    }
    std::cout << (!good ? "YES" : "NO") << '\n';
  }
  exit(0);
}