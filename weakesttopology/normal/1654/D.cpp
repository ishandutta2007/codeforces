#include <bits/stdc++.h>

template <uint32_t P>
struct Z {
  uint32_t x;
  Z() : x(0) {}
  Z(int64_t x_) {
    x_ %= P;
    if (x_ < 0) x_ += P;
    x = x_;
  }
  Z& operator+=(Z rhs) {
    x += rhs.x;
    if (x >= P) x -= P;
    return *this;
  }
  Z& operator-=(Z rhs) {
    x += P - rhs.x;
    if (x >= P) x -= P;
    return *this;
  }
  Z& operator*=(Z rhs) {
    x = uint64_t(x) * rhs.x % P;
    return *this;
  }
  Z& operator/=(Z rhs) {
    return *this *= rhs.power(-1);
  }
  Z power(int64_t p) const {
    p %= P - 1;
    if (p < 0) p += P - 1;
    Z res = 1;
    for (Z y = *this; p; p >>= 1, y *= y) {
      if (p & 1) res *= y;
    }
    return res;
  }
  Z operator-() const {
    return Z() - *this;
  }
  bool operator==(Z rhs) const {
    return x == rhs.x;
  }
  bool operator!=(Z rhs) const {
    return x != rhs.x;
  }
  friend Z operator+(Z lhs, Z rhs) {
    return lhs += rhs;
  }
  friend Z operator-(Z lhs, Z rhs) {
    return lhs -= rhs;
  }
  friend Z operator*(Z lhs, Z rhs) {
    return lhs *= rhs;
  }
  friend Z operator/(Z lhs, Z rhs) {
    return lhs /= rhs;
  }
  friend std::ostream& operator<<(std::ostream& out, Z a) {
    return out << a.x;
  }
  friend std::istream& operator>>(std::istream& in, Z& a) {
    int64_t x;
    in >> x;
    a = Z(x);
    return in;
  }
};
using Zp = Z<998244353>;

std::pair<std::vector<int>, std::vector<int>> sieve(int N) {
  std::vector<int> lp(N + 1), pr;
  for (int i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      pr.push_back(lp[i] = i);
    }
    for (auto p : pr) {
      if (p > lp[i] || i * p > N) break;
      lp[i * p] = p;
    }
  }
  return {lp, pr};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<std::vector<std::tuple<int, int, int>>> E(N);
    for (int i = 0; i < N - 1; ++i) {
      int u, v, x, y;
      std::cin >> u >> v >> x >> y;
      --u, --v;
      E[u].emplace_back(v, y, x);
      E[v].emplace_back(u, x, y);
    }
    auto lp = sieve(N).first;
    std::vector<int> e(N + 1), min(N + 1);
    auto update = [&](int x, int coef) {
      while (x > 1) {
        int p = lp[x];
        while (x % p == 0) {
          e[p] += coef;
          x /= p;
        }
        min[p] = std::min(min[p], e[p]);
      }
    };
    std::vector<Zp> f(N);
    f[0] = 1;
    auto dfs = [&](auto& self, int u, int p) -> void {
      for (auto [v, x, y] : E[u]) {
        if (v == p) continue;
        f[v] = (f[u] * x) / y;
        update(x, +1);
        update(y, -1);
        self(self, v, u);
        update(y, +1);
        update(x, -1);
      }
    };
    dfs(dfs, 0, -1);
    Zp a = 1;
    for (int p = 1; p <= N; ++p) {
      for (int i = 0; i < -min[p]; ++i) {
        a = a * p;
      }
    }
    Zp res = 0;
    for (int u = 0; u < N; ++u) {
      res += f[u] * a;
    }
    std::cout << res << '\n';
  }
  exit(0);
}