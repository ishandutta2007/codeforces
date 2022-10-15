#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, L;
    std::cin >> N >> L;
    std::vector<int> cnt(L);
    for (int i = 0; i < N; ++i) {
      int x;
      std::cin >> x;
      for (int l = 0; l < L; ++l) {
        cnt[l] += x >> l & 1;
      }
    }
    int y = 0;
    for (int l = 0; l < L; ++l) {
      if (cnt[l] >= N - cnt[l]) {
        y ^= 1 << l;
      }
    }
    std::cout << y << '\n';
  }
  exit(0);
}