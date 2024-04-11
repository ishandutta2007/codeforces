#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N, M;
  std::cin >> N >> M;

  std::vector<int> uf(M);
  std::iota(uf.begin(), uf.end(), 0);
  std::vector<bool> marked(M);
  std::vector<int> basis;

  auto Find = [&](auto dfs, int x) -> int {
    if (x == uf[x]) return x;
    return uf[x] = dfs(dfs, uf[x]);
  };

  int ans = 0;

  for (int i = 0; i < N; ++i) {
    int k;
    std::cin >> k;
    if (k == 1) {
      int x;
      std::cin >> x;
      x--;
      x = Find(Find, x);
      if (!marked[x]) {
        marked[x] = true;
        basis.push_back(i);
      }
    } else {
      int x, y;
      std::cin >> x >> y;
      x--;
      y--;
      x = Find(Find, x);
      y = Find(Find, y);
      if (x != y && (!marked[x] || !marked[y])) {
        uf[x] = y;
        marked[y] = marked[x] || marked[y];
        basis.push_back(i);
      }
    }
  }

  constexpr int kP = 1'000'000'000 + 7;

  int res = 1;
  for (int i = 0; i < basis.size(); ++i) res = (res + res) % kP;

  std::cout << res << " " << basis.size() << "\n";
  for (int b : basis) std::cout << b + 1 << " ";
  std::cout << "\n";
  return 0;
}