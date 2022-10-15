#include <bits/stdc++.h>
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
    --a[i];
  }
  std::vector<uint64_t> h(N), hsum(N);
  for (int i = 0; i < N; ++i) {
    h[i] = rng();
  }
  std::partial_sum(h.begin(), h.end(), hsum.begin(), std::bit_xor<uint64_t>());
  int ans = 0;
  for (int t = 0; t < 2; ++t) {
    std::reverse(a.begin(), a.end());
    std::vector<bool> on(N);
    for (int m = 0; m < N; ++m) {
      if (a[m] != 0) continue;
      std::vector<uint64_t> hs = {0};
      on[0] = true;
      for (int i = m - 1; i >= 0 && !on[a[i]]; --i) {
        int x = a[i];
        on[x] = true;
        hs.push_back(hs.back() ^ h[x]);
      }
      for (int i = m; i >= 0 && on[a[i]]; --i) {
        on[a[i]] = false;
      }
      std::sort(hs.begin(), hs.end());
      int max = 0;
      uint64_t sum = 0;
      for (int i = m; i < N && !on[a[i]]; ++i) {
        int x = a[i];
        on[x] = true;
        max = std::max(max, x);
        sum ^= h[x];
        ans += std::binary_search(hs.begin(), hs.end(), hsum[max] ^ sum);
      }
      for (int i = m; i < N && on[a[i]]; ++i) {
        on[a[i]] = false;
      }
    }
  }
  ans -= std::count(a.begin(), a.end(), 0);
  std::cout << ans << '\n';
  exit(0);
}