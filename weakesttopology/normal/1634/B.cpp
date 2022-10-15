#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    int64_t x, y;
    std::cin >> N >> x >> y;
    x &= 1;
    y &= 1;
    for (int i = 0; i < N; ++i) {
      int A;
      std::cin >> A;
      x ^= A & 1;
    }
    std::cout << (x == y ? "Alice" : "Bob") << '\n';
  }
  exit(0);
}