#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<std::queue<int>> q(N + 1);
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> a[i];
      q[a[i]].push(i);
    }
    std::vector<int> b;
    int ptr = 0;
    while (!q[0].empty()) {
      int mex = 0, max = -1;
      while (!q[mex].empty()) {
        max = std::max(max, q[mex].front());
        ++mex;
      }
      b.push_back(mex);
      while (ptr <= max) {
        q[a[ptr]].pop();
        ++ptr;
      }
    }
    for (int i = 0; i < N - ptr; ++i) {
      b.push_back(0);
    }
    std::cout << b.size() << '\n';
    for (auto x : b) {
      std::cout << x << ' ';
    }
    std::cout << '\n';
  }
  exit(0);
}