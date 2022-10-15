#include <bits/stdc++.h>
constexpr int inf = 1e9;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  int max = 0;
  for (int i = 0; i < N; ++i) {
    max += i / 2;
  }
  if (max < M) {
    std::cout << "-1\n";
    exit(0);
  }
  std::vector<int> a = {1};
  auto count = [&](int x) {
    int r = a.size() - 1;
    int res = 0;
    for (int l = 0; l < r; ++l) {
      while (r > l && a[l] + a[r] > x) --r;
      if (r > l) {
        res += a[l] + a[r] == x;
      }
    }
    return res;
  };
  for (int i = 2; i <= N; ++i) {
    if ((i - 1) / 2 <= M) {
      a.push_back(i);
      M -= (i - 1) / 2;
    } else {
      int x = i;
      while (count(x) > M) ++x;
      assert(count(x) == M);
      a.push_back(x);
      break;
    }
  }
  int step = 3 * N;
  while (a.size() < N) {
    a.push_back(inf - N * step + step * a.size());
  }
  for (int i = 0; i < N; ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
  std::cerr << "M == " << M << std::endl;
  exit(0);
}