#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<int> cnt(N + 1);
    for (int i = 0; i < N; ++i) {
      int l, r;
      std::cin >> l >> r;
      --l;
      ++cnt[l];
      --cnt[r];
    }
    std::partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    std::vector<std::tuple<int, int, int>> ans;
    auto solve = [&](auto& self, int l, int r) -> void {
      if (r <= l) return;
      int d = std::find(cnt.begin(), cnt.end(), 1) - cnt.begin();
      ans.emplace_back(l, r, d);
      for (int i = l; i < r; ++i) {
        --cnt[i];
      }
      self(self, l, d);
      self(self, d + 1, r);
    };
    solve(solve, 0, N);
    for (auto [l, r, d] : ans) {
      std::cout << l + 1 << ' ' << r << ' ' << d + 1 << '\n';
    }
  }
  exit(0);
}