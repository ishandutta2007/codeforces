#include <bits/stdc++.h>

constexpr int K = 20, N = 1e5;

struct two_pointers_t {
  std::vector<int> D[N + 1];
  int phi[N + 1];
  int64_t g[N + 1], cost;
  two_pointers_t() {
    for (int n = 1; n <= N; ++n) {
      for (int m = n; m <= N; m += n) {
        D[m].push_back(n);
      }
      std::reverse(D[n].begin(), D[n].end());
    }
    std::iota(std::begin(phi), std::end(phi), 0);
    for (int n = 2; n <= N; ++n) {
      if (phi[n] != n) continue;
      for (int m = n; m <= N; m += n) {
        phi[m] -= phi[m] / n;
      }
    }
    cost = g[1] = 1;
  }
  int l = 1, r = 1;
  void add_left() {
    --l;
    int64_t sz = r / l;
    g[l] = 1LL * sz * (sz + 1) / 2;
    for (int i = 2 * l; i <= r; i += l) {
      g[l] -= g[i];
    }
    cost += g[l];
  }
  void remove_left() {
    cost -= g[l];
    g[l] = 0;
    ++l;
  }
  void update_right(int sgn) {
    for (int d : D[r]) {
      if (d < l) break;
      g[d] += sgn * phi[r / d];
      cost += sgn * phi[r / d];
    }
  }
  void add_right() {
    ++r;
    update_right(+1);
  }
  void remove_right() {
    update_right(-1);
    --r;
  }
  int64_t query(int ql, int qr) {
    while (ql < l) add_left();
    while (r < qr) add_right();
    while (l < ql) remove_left();
    while (qr < r) remove_right();
    return cost;
  }
} two_pointers;

int64_t dp[N + 1][K + 1];

void solve(int k, int l, int r, int optl, int optr) {
  if (r < l) return;
  int m = (l + r) / 2, opt = -1;
  int cnt = 0;
  for (int i = std::min(m, optr); i >= optl; --i) {
    int64_t nvalue = two_pointers.query(i, m) + dp[i - 1][k];
    if (nvalue < dp[m][k + 1]) {
      dp[m][k + 1] = nvalue;
      opt = i;
    }
  }
  solve(k, l, m - 1, optl, opt);
  solve(k, m + 1, r, opt, optr);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::memset(dp, 0x3f, sizeof(dp));
  std::fill(std::begin(dp[0]), std::end(dp[0]), 0);
  for (int k = 0; k < K; ++k) {
    solve(k, 1, N, 1, N);
  }
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, k;
    std::cin >> n >> k;
    std::cout << dp[n][std::min(k, K)] << '\n';
  }
  exit(0);
}