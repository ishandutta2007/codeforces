#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    int max = 0, res = 0;
    for (int i = 0; i < N; ++i) {
      int a;
      std::cin >> a;
      res = std::max(res, max + a);
      max = std::max(max, a);
    }
    std::cout << res << '\n';
  }
  exit(0);
}