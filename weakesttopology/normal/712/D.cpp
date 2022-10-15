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
using Zp = Z<(int)1e9 + 7>;

template <typename T>
struct Combinatorics {
  std::vector<T> f, inv, pref, suff;
  Combinatorics(int N) : f(N), inv(N), pref(N), suff(N) {
    f[0] = inv[0] = 1;
    for (int x = 1; x < N; ++x) {
      f[x] = x * f[x - 1];
      inv[x] = 1 / f[x];
    }
  }
  T C(int n, int k) {
    return k < 0 || n < k ? 0 : f[n] * inv[k] * inv[n - k];
  }
  T S(int n, int k) {
    return k == 0 ? n == 0 : C(n + k - 1, k - 1);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int a, b, k, t;
  std::cin >> a >> b >> k >> t;
  int deg = (2 * k + 1) * 2 * t;
  Combinatorics<Zp> C(2 * deg + 1);
  std::vector<Zp> coef(deg + 1);
  for (int l = 0; l <= 2 * t; ++l) {
    coef[(2 * k + 1) * l] = C.C(2 * t, l) * (l % 2 ? -1 : +1);
  }
  coef.push_back(0);
  std::partial_sum(coef.rbegin(), coef.rend(), coef.rbegin());
  Zp res = 0;
  for (int i = 0; i - 2 * t * k <= deg; ++i) {
    Zp c = C.S(i, 2 * t);
    int e = i - 2 * t * k;
    // std::max(-2 * k * t, b - a + 1) <= j + e <= 2 * k * t
    int l = std::max(0, std::max(b - a + 1, -2 * k * t)  - e);
    int r = std::min(deg, 2 * k * t - e);
    if (l <= r) {
      res += c * (coef[l] - coef[r + 1]);
    }
  }
  std::cout << res << '\n';
  exit(0);
}