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

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, K;
  int64_t a0, x, y, M;
  std::cin >> N >> a0 >> x >> y >> K >> M;
  int lcm = 1;
  for (int k = 1; k <= K - 1; ++k) {
    lcm = std::lcm(lcm, k);
  }
  std::vector<Zp> dp(lcm);
  Zp P = Zp(1) / N, Q = 1 - P;
  for (int k = K; k >= 1; --k) {
    std::vector<Zp> ndp(lcm);
    for (int a = 0; a < lcm; ++a) {
      ndp[a] = P * (a + dp[a - a % k]) + Q * dp[a];
    }
    std::swap(dp, ndp);
  }
  Zp res = 0;
  int64_t a = a0;
  for (int i = 0; i < N; ++i) {
    int r = a % lcm;
    res += dp[r] + K * P * (a - r);
    a = (x * a + y) % M;
  }
  res *= Zp(N).power(K);
  std::cout << res << '\n';
  exit(0);
}