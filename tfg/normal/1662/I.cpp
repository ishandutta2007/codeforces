#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

#include <map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  std::vector<int> p(N), x(M);
  for (int i = 0; i < N; ++i) {
    std::cin >> p[i];
  }
  for (int j = 0; j < M; ++j) {
    std::cin >> x[j];
  }
  std::sort(x.begin(), x.end());
  std::map<int, long long> add;
  for (int i = 0, l = 0; i < N; ++i) {
    int t = i * 100;
    while (l + 1 < M && x[l + 1] <= t) ++l;
    int d = std::abs(t - x[l]);
    if (l + 1 < M) {
      d = std::min(d, x[l + 1] - t);
    }
    add[t - d] += p[i];
    add[t + d] -= p[i];
  }
  long long max = 0, sum = 0;
  for (auto [_, x] : add) {
    sum += x;
    max = std::max(max, sum);
  }
  std::cout << max << '\n';
  exit(0);
}