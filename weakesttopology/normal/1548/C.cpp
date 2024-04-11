#include <bits/stdc++.h>

template <uint32_t P>
struct Z {
  uint32_t x;
  constexpr Z() : x(0) {}
  template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
  constexpr Z(T a) : x(((a % P) + P) % P) {}
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
    return *this *= pow(rhs, -1);
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

template <uint32_t P>
Z<P> pow(Z<P> x, int64_t p) {
  p %= P - 1;
  if (p < 0) p += P - 1;
  Z<P> res = 1;
  while (p) {
    if (p & 1) {
      res *= x;
    }
    x *= x;
    p >>= 1;
  }
  return res;
}

using Zp = Z<(int)1e9 + 7>;

std::vector<Zp> operator*(const std::vector<Zp>& a, const std::vector<Zp>& b) {
  int N = a.size(), M = b.size();
  std::vector<Zp> c(N + M - 1);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      c[i + j] += a[i] * b[j];
    }
  }
  return c;
}

std::vector<Zp> operator/(std::vector<Zp> a, const std::vector<Zp>& b) {
  std::vector<Zp> c;
  while (a.size() >= b.size()) {
    c.push_back(a.back() / b.back());
    for (int i = 0; i < b.size(); ++i) {
      a.rbegin()[i] -= c.back() * b.rbegin()[i];
    }
    a.pop_back();
  }
  std::reverse(c.begin(), c.end());
  assert(a == std::vector<Zp>(a.size()));
  return c;
}

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
  int N, Q;
  std::cin >> N >> Q;
  std::vector<Zp> p = {1, 1};
  p = p * p * p;
  Combinatorics<Zp> C(3 * N + 1);
  std::vector<Zp> a(3 * N + 1), b = p;
  b[0] -= 1;
  for (int k = 1; k <= 3 * N; ++k) {
    a[k] = C.C(3 * N, k);
  }
  auto res = p * (a / b);
  for (int q = 0; q < Q; ++q) {
    int x;
    std::cin >> x;
    std::cout << res[x] << '\n';
  }
  exit(0);
}