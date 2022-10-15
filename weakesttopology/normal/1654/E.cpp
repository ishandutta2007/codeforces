#include <bits/stdc++.h>

constexpr int magic = 600;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  int max = 0;
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
    max = std::max(max, a[i]);
  }
  std::vector<int> cnt_(2 * max + 1);
  int* cnt = cnt_.data() + max;
  int res = N - 1;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < i + magic && j < N; ++j) {
      int x = a[j] - a[i], y = j - i;
      if (x % y) continue;
      int d = x / y;
      ++cnt[d];
      res = std::min(res, N - 1 - cnt[d]);
    }
    for (int j = i + 1; j < i + magic && j < N; ++j) {
      int x = a[j] - a[i], y = j - i;
      if (x % y) continue;
      int d = x / y;
      --cnt[d];
    }
  }
  for (int d = -max / magic; d <= max / magic; ++d) {
    std::vector<int64_t> b(N);
    for (int i = 0; i < N; ++i) {
      b[i] = a[i] - 1LL * i * d;
    }
    std::sort(b.begin(), b.end());
    for (auto iter = b.begin(); iter != b.end();) {
      int cnt = 0, x = *iter;
      while (iter != b.end() && *iter == x) {
        ++cnt;
        ++iter;
      }
      res = std::min(res, N - cnt);
    }
  }
  std::cout << res << '\n';
  exit(0);
}