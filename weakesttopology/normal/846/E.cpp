#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<int64_t> b(N), a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }
  std::vector<int> x(N), k(N);
  for (int u = 1; u < N; ++u) {
    std::cin >> x[u] >> k[u];
    --x[u];
  }
  bool good = true;
  for (int u = N - 1; u > 0; --u) {
    int v = x[u];
    if (b[u] >= a[u]) {
      b[v] += b[u] - a[u];
    } else {
      int64_t need;
      if (__builtin_mul_overflow(a[u] - b[u], k[u], &need) ||
          __builtin_add_overflow(a[v], need, &a[v])) {
        good = false;
        break;
      }
    }
  }
  std::cout << (good && a[0] <= b[0] ? "YES" : "NO") << '\n';
  exit(0);
}