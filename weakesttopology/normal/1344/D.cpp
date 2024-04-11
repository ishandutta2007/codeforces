#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

constexpr long long inf = std::numeric_limits<long long>::max() / 2;

auto D(long long a) {
  return [a](long long x) { return x < a ? a - 3 * x * x - 3 * x - 1 : inf; };
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  long long K;
  std::cin >> N >> K;

  std::vector<long long> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  auto get = [&](long long d) {
    std::vector<long long> b(N);
    for (int i = 0; i < N; ++i) {
      long long l = -1, r = a[i];
      while (l + 1 < r) {
        long long m = (l + r) / 2;
        D(a[i])(m) >= d ? l = m : r = m;
      }
      b[i] = r;
    }
    return b;
  };

  long long L = -inf, R = inf;

  while (L + 1 < R) {
    long long M = L + (R - L) / 2;
    auto b = get(M);
    auto k = std::accumulate(b.begin(), b.end(), 0LL);
    k <= K ? R = M : L = M;
  }

  auto b = get(R);
  long long k = std::accumulate(b.begin(), b.end(), 0LL);

  for (int i = 0; i < N; ++i) {
    if (k < K && D(a[i])(b[i]) == L) {
      ++k;
      ++b[i];
    }
    std::cout << b[i] << ' ';
  }
  std::cout << std::endl;

  assert(k == K);

  exit(0);
}