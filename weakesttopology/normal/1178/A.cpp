#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }
  std::vector<int> I(N - 1);
  std::iota(I.begin(), I.end(), 1);
  std::sort(I.begin(), I.end(), [&](int i, int j) { return a[i] < a[j]; });
  std::vector<int> J = {0};
  int coalition = a[0];
  for (auto i : I) {
    if (2 * a[i] <= a[0]) {
      coalition += a[i];
      J.push_back(i);
    }
  }
  int tot = std::accumulate(a.begin(), a.end(), 0);
  if (coalition > tot / 2) {
    std::cout << J.size() << '\n';
    for (auto j : J) {
      std::cout << j + 1 << ' ';
    }
    std::cout << '\n';
  } else {
    std::cout << "0\n";
  }
  exit(0);
}