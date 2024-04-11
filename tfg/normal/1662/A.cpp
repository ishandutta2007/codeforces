#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int maxb[10]{};
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
      int b, d;
      std::cin >> b >> d;
      --d;
      maxb[d] = std::max(maxb[d], b);
    }
    int sum = 0;
    bool moreproblems = false;
    for (int d = 0; d < 10; ++d) {
      if (maxb[d] == 0) {
        moreproblems = true;
        break;
      }
      sum += maxb[d];
    }
    if (moreproblems) {
      std::cout << "MOREPROBLEMS\n";
    } else {
      std::cout << sum << '\n';
    }
  }
  exit(0);
}