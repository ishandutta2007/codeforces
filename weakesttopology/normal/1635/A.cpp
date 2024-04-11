#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int x;
      std::cin >> x;
      ans |= x;
    }
    std::cout << ans << '\n';
  }
  exit(0);
}