#include <bits/stdc++.h>

template <uint32_t P>
struct Z {
  uint32_t x;
  constexpr Z() : x(0) {}
  template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
  constexpr Z(T a) : x(((int64_t(a) % P) + P) % P) {}
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
using Zp = Z<(int)1e9 + 7>;

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

template <typename T>
std::vector<T> operator*(const std::vector<T>& P, const std::vector<T>& Q) {
  int N = P.size(), M = Q.size();
  std::vector<T> R(N + M - 1);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      R[i + j] += P[i] * Q[j];
    }
  }
  return R;
}

template <typename T>
std::vector<T> operator%(std::vector<T> P, const std::vector<T>& Q) {
  while (Q.size() <= P.size()) {
    T c = P.back() / Q.back();
    for (int i = 0; i < Q.size(); ++i) {
      P.rbegin()[i] -= c * Q.rbegin()[i];
    }
    P.pop_back();
  }
  return P;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int F, B;
  int64_t N;
  std::cin >> F >> B >> N;
  std::vector<int> p(F), c(B);
  for (int i = 0; i < F; ++i) {
    std::cin >> p[i];
  }
  for (int i = 0; i < B; ++i) {
    std::cin >> c[i];
  }
  int cmax = *std::max_element(c.begin(), c.end());
  std::vector<Zp> f(cmax + 1);
  f[cmax] = 1;
  for (int i = 0; i < B; ++i) {
    f[cmax - c[i]] -= 1;
  }
  std::vector<Zp> y(cmax);
  for (int i = 0; i < F; ++i) {
    std::vector<Zp> r = {1}, x = std::vector<Zp>{0, 1} % f;
    for (int e = p[i]; e; e >>= 1) {
      if (e & 1) {
        r = (r * x) % f;
      }
      x = (x * x) % f;
    }
    for (int j = 0; j < r.size(); ++j) {
      y[j] += r[j];
    }
  }
  std::vector<Zp> r = {1};
  for (int64_t e = N; e; e >>= 1) {
    if (e & 1) {
      r = (r * y) % f;
    }
    y = (y * y) % f;
  }
  std::vector<Zp> dp(cmax);
  dp[0] = 1;
  Zp res = 0;
  for (int i = 0; i < r.size(); ++i) {
    for (int j = 0; j < B; ++j) {
      int ni = i + c[j];
      if (ni < cmax) {
        dp[ni] += dp[i];
      }
    }
    res += dp[i] * r[i];
  }
  std::cout << res << '\n';
  exit(0);
}