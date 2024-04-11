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
    int N, M;
    std::cin >> N >> M;
    int max[2]{};
    for (int j = 0; j < M; ++j) {
      for (int o : {0, 1}) {
        int x;
        std::cin >> x;
        max[o] = std::max(max[o], x);
      }
    }
    std::string res;
    if (max[0] + max[1] > N) {
      res = "IMPOSSIBLE";
    } else {
      res.resize(N, 'W');
      std::fill_n(res.begin(), max[0], 'R');
    }
    std::cout << res << '\n';
  }
  exit(0);
}