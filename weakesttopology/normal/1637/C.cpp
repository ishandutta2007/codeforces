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
    int64_t ans = 0;
    int cnt_odd = 0, cnt_big = 0;
    bool big_even = false;
    for (int i = 1; i < N - 1; ++i) {
      ans += (a[i] + 1) / 2;
      if (a[i] >= 2) {
        ++cnt_big;
        if (a[i] % 2 == 0) {
          big_even = true;
        }
      }
      if (a[i] % 2) {
        ++cnt_odd;
      }
    }
    if (cnt_odd && (!big_even && (cnt_big == 0 || cnt_odd == 1))) {
      std::cout << "-1\n";
      continue;
    }
    std::cout << ans << '\n';
  }
  exit(0);
}