#include <bits/stdc++.h>

struct G {
  inline static int K;
  int x;
  G(int x = 0) : x(x) {}
  friend G operator+(G lhs, G rhs) {
    G res;
    for (int a = lhs.x, b = rhs.x, pow = 1; a || b; pow *= K, a /= K, b /= K) {
      res.x += pow * ((a % K + b % K) % K);
    }
    return res;
  }
  G operator-() const {
    G res;
    for (int a = x, pow = 1; a; pow *= K, a /= K) {
      res.x += pow * ((K - a % K) % K);
    }
    return res;
  }
  friend G operator-(G lhs, G rhs) {
    return lhs + (-rhs);
  }
};

bool query(G y) {
  std::cout << y.x << std::endl;
  int r;
  std::cin >> r;
  if (r == -1) {
    exit(0);
  }
  return r;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N >> G::K;
    G y;
    for (int x = 0; x < N; ++x) {
      G z = y + (x % 2 ? -G(x) : G(x));
      if (query(z)) break;
      y = z - y;
    }
  }
  exit(0);
}