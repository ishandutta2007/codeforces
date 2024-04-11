#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    if (N % 7) {
      N -= N % 10;
      while (N % 7) ++N;
    }
    std::cout << N << '\n';
  }
  exit(0);
}