#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, M, rb, cb, rd, cd;
    std::cin >> N >> M >> rb >> cb >> rd >> cd;
    int a = rb <= rd ? rd - rb : N - rb + N - rd;
    int b = cb <= cd ? cd - cb : M - cb + M - cd;
    int res = std::min(a, b);
    std::cout << res << '\n';
  }
  exit(0);
}