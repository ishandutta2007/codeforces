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

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, K;
  std::cin >> N >> K;
  std::vector<Zp> dp(K + 1);
  dp[1] = 1;
  for (int i = 1; i <= K; ++i) {
    for (int j = 2 * i; j <= K; j += i) {
      dp[j] -= dp[i];
    }
  }
  std::vector<Zp> power(K + 1);
  for (int k = 0; k <= K; ++k) {
    power[k] = Zp(k).power(N);
  }
  std::vector<Zp> add(K + 1);
  Zp cnt = 0, ans = 0;
  for (int i = 1; i <= K; ++i) {
    for (int j = i; j <= K; j += i) {
      add[j] += (power[j / i] - power[j / i - 1]) * dp[i];
    }
    cnt += add[i];
    ans += cnt.x ^ i;
  }
  std::cout << ans << '\n';
  exit(0);
}