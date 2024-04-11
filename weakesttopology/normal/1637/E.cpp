#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> a[i];
    }
    auto v = a;
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    int M = v.size();
    std::vector<int> cnt(M);
    for (int i = 0; i < N; ++i) {
      int j = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
      ++cnt[j];
    }
    auto cs = cnt;
    std::sort(cs.begin(), cs.end());
    cs.erase(std::unique(cs.begin(), cs.end()), cs.end());
    int K = cs.size();
    std::vector<std::vector<int>> Js(K);
    for (int j = 0; j < M; ++j) {
      int k = std::lower_bound(cs.begin(), cs.end(), cnt[j]) - cs.begin();
      Js[k].push_back(j);
    }
    for (int k = 0; k < K; ++k) {
      std::sort(Js[k].begin(), Js[k].end(), [&](int j1, int j2) { return v[j1] > v[j2]; });
    }
    std::vector<std::vector<int>> ban(M);
    for (int q = 0; q < Q; ++q) {
      int x, y;
      std::cin >> x >> y;
      x = std::lower_bound(v.begin(), v.end(), x) - v.begin();
      y = std::lower_bound(v.begin(), v.end(), y) - v.begin();
      ban[x].push_back(y);
      ban[y].push_back(x);
    }
    long long ans = 0;
    std::vector<bool> dead(M);
    for (int j = 0; j < M; ++j) {
      dead[j] = true;
      for (auto u : ban[j]) {
        dead[u] = true;
      }
      for (int k = 0; k < K; ++k) {
        for (auto l : Js[k]) {
          if (!dead[l]) {
            ans = std::max(ans, 1LL * (v[j] + v[l]) * (cnt[j] + cnt[l]));
            break;
          }
        }
      }
      dead[j] = false;
      for (auto u : ban[j]) {
        dead[u] = false;
      }
    }
    std::cout << ans << '\n';
  }
  exit(0);
}