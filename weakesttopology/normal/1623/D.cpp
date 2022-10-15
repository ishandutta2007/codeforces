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
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N[2], x[2], y[2];
    std::cin >> N[0] >> N[1];
    for (int t : {0, 1}) {
      std::cin >> x[t];
      --x[t];
    }
    for (int t : {0, 1}) {
      std::cin >> y[t];
      --y[t];
    }
    Zp p;
    std::cin >> p;
    p /= 100;
    int z[2] = {x[0], x[1]}, d[2] = {+1, +1};
    auto fix = [&]() {
      for (int t : {0, 1}) {
        int nz = z[t] + d[t];
        if (nz < 0 || N[t] <= nz) {
          d[t] *= -1;
        }
      }
    };
    fix();
    int c[2] = {d[0], d[1]};
    Zp E = 0, q = 1;
    int k = 0;
    do {
      if (z[0] == y[0] || z[1] == y[1]) {
        E += k * p * q;
        q *= 1 - p;
      }
      ++k;
      for (int t : {0, 1}) {
        z[t] += d[t];
        fix();
      }
    } while (z[0] != x[0] || z[1] != x[1] || d[0] != c[0] || d[1] != c[1]);
    E /= 1 - q;
    E += k * (1 / (1 - q) - 1);
    std::cout << E << '\n';
  }
  exit(0);
}