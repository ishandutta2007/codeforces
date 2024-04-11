#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> a[i];
    }
    int64_t res = 0;
    for (int l = 0; l < N; ++l) {
      int cnt = 0;
      for (int r = l; r < N; ++r) {
        cnt += !a[r];
        res += r - l + 1 + cnt;
      }
    }
    std::cout << res << '\n';
  }
  exit(0);
}