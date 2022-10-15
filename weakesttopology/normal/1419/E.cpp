#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<int> ds;
    for (int d = 2; d * d <= N; ++d) {
      if (N % d == 0) {
        ds.push_back(d);
        if (N / d != d) {
          ds.push_back(N / d);
        }
      }
    }
    int M = N;
    std::vector<int> ps;
    for (int p = 2; p * p <= M; ++p) {
      if (M % p == 0) {
        ps.push_back(p);
        while (M % p == 0) M /= p;
      }
    }
    if (M > 1) {
      ps.push_back(M);
    }
    int K = ps.size();
    std::vector<int> C = {N};
    for (int j = 0; j < K; ++j) {
      auto nend = std::partition(ds.begin(), ds.end(),
          [&](auto d) { return d % ps[j]; });
      int take = ds.end() - nend;
      int last = -1;
      while (take--) {
        int d = *ds.rbegin();
        ds.pop_back();
        if (d % ps[(j + 1) % K] == 0 && last == -1) {
          last = d;
        } else {
          C.push_back(d);
        }
      }
      if (last != -1) {
        C.push_back(last);
      }
    }
    assert(ds.empty());
    for (auto d : C) {
      std::cout << d << ' ';
    }
    std::cout << '\n';
    int cost = 0;
    int D = C.size();
    for (int i = 0; i < D; ++i) {
      cost += std::gcd(C[i], C[(i + 1) % D]) == 1;
    }
    std::cout << std::flush;
    assert(cost <= 1);
    std::cout << cost << '\n';
  }
  exit(0);
}