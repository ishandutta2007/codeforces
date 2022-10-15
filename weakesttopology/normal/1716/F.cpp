#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

#include <type_traits>

template <unsigned P>
struct Z {
  unsigned value;

  constexpr Z() : value(0) {}

  template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
  constexpr Z(T a) : value((((long long)a % P) + P) % P) {}

  Z& operator+=(Z rhs) {
    value += rhs.value;
    if (value >= P) value -= P;
    return *this;
  }

  Z& operator-=(Z rhs) {
    value += P - rhs.value;
    if (value >= P) value -= P;
    return *this;
  }

  Z& operator*=(Z rhs) {
    value = (unsigned long long)value * rhs.value % P;
    return *this;
  }

  Z& operator/=(Z rhs) { return *this *= pow(rhs, -1); }

  Z operator+() const { return *this; }

  Z operator-() const { return Z() - *this; }

  bool operator==(Z rhs) const { return value == rhs.value; }

  bool operator!=(Z rhs) const { return value != rhs.value; }

  friend Z operator+(Z lhs, Z rhs) { return lhs += rhs; }

  friend Z operator-(Z lhs, Z rhs) { return lhs -= rhs; }

  friend Z operator*(Z lhs, Z rhs) { return lhs *= rhs; }

  friend Z operator/(Z lhs, Z rhs) { return lhs /= rhs; }

  friend std::ostream& operator<<(std::ostream& out, Z a) { return out << a.value; }

  friend std::istream& operator>>(std::istream& in, Z& a) {
    long long value;
    in >> value;
    a = Z(value);
    return in;
  }
};

template <unsigned P>
Z<P> pow(Z<P> x, long long p) {
  if (x == 0) {
    return p == 0 ? 1 : 0;
  }
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

using Zp = Z<998244353>;

constexpr int Kmax = 2000;

Zp S[Kmax + 1][Kmax + 1];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  S[0][0] = 1;
  for (int n = 1; n <= Kmax; ++n) {
    for (int k = 1; k <= n; ++k) {
      S[n][k] = S[n - 1][k - 1] + k * S[n - 1][k];
    }
  }

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, M, K;
    std::cin >> N >> M >> K;
    Zp r = (M + 1) / 2, rpow = 1;
    Zp x = pow(Zp(M), N), inv = 1 / Zp(M);
    Zp f = 1;
    Zp ans = 0;
    for (int l = 0; l <= K; ++l) {
      ans += S[K][l] * rpow * f * x;
      rpow *= r;
      x *= inv;
      f *= N - l;
    }
    std::cout << ans << '\n';
  }

  exit(0);
}