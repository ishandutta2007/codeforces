#include <bits/stdc++.h>

constexpr int K = 5;
using Array = std::array<int, K>;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const size_t X = rng();

struct custom_hash {
  size_t operator()(const Array& a) const {
    size_t hash = 1;
    for (auto c : a) {
      hash *= X + c;
    }
    return hash;
  }
};

Array discard(Array a, int mask) {
  for (int k = 0; k < K; ++k) {
    if (mask >> k & 1) continue;
    a[k] = 0;
  }
  std::sort(a.begin(), a.end());
  return a;
}

struct InclusionExclusion {
  std::unordered_map<Array, int, custom_hash> f;
  void update(const Array& a, int value) {
    for (int mask = 0; mask < (1 << K); ++mask) {
      f[discard(a, mask)] += value;
    }
  }
  int query(const Array& a) {
    int res = 0;
    for (int mask = 0; mask < (1 << K); ++mask) {
      int sgn = std::popcount((unsigned)mask) % 2 ? -1 : +1;
      res += sgn * f[discard(a, mask)];
    }
    assert(res >= 0);
    return res;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  std::vector<std::array<int, K>> a(N);
  std::vector<int> w(N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> a[i][j];
    }
    for (int j = M; j < K; ++j) {
      a[i][j] = -i;
    }
    std::cin >> w[i];
  }
  std::vector<int> I(N);
  std::iota(I.begin(), I.end(), 0);
  std::sort(I.begin(), I.end(), [&](int i, int j) { return w[i] < w[j]; });
  InclusionExclusion ie;
  int R = 0;
  while (R < N) {
    int i = I[R];
    if (ie.query(a[i])) {
      break;
    } else {
      ie.update(a[i], +1);
      ++R;
    }
  }
  if (R == N) {
    std::cout << -1 << '\n';
  } else {
    int res = std::numeric_limits<int>::max();
    int L = R - 1;
    for (int i = R; i < N; ++i) {
      int j = I[i];
      while (ie.query(a[j])) {
        int k = I[L];
        res = std::min(res, w[j] + w[k]);
        ie.update(a[k], -1);
        --L;
      }
    }
    std::cout << res << '\n';
  }
  exit(0);
}