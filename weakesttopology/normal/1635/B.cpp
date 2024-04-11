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
    auto valid = [&](int i) {
      return 0 <= i && i < N;
    };
    auto local_max = [&](int i) {
      return valid(i - 1) && valid(i + 1) &&
        a[i] > std::max(a[i - 1], a[i + 1]);
    };
    int cost = 0;
    for (int i = 0; i < N; ++i) {
      if (local_max(i)) {
        ++cost;
        for (int j : {i, i + 2}) {
          if (valid(j)) {
            a[i + 1] = std::max(a[i + 1], a[j]);
          }
        }
      }
    }
    std::cout << cost << '\n';
    for (int i = 0; i < N; ++i) {
      assert(!local_max(i));
      std::cout << a[i] << ' ';
    }
    std::cout << '\n';
  }
  exit(0);
}