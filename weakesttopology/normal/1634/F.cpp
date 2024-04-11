#include <bits/stdc++.h>

struct Z {
  inline static uint32_t m;
  uint32_t x;
  Z() : x(0) {}
  Z(int64_t x_) {
    x_ %= m;
    if (x_ < 0) x_ += m;
    x = x_;
  }
  Z& operator+=(Z rhs) {
    x += rhs.x;
    if (x >= m) x -= m;
    return *this;
  }
  Z& operator-=(Z rhs) {
    x += m - rhs.x;
    if (x >= m) x -= m;
    return *this;
  }
  Z& operator*=(Z rhs) {
    x = uint64_t(x) * rhs.x % m;
    return *this;
  }
  Z power(int64_t p) const {
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

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, Q;
  std::cin >> N >> Q >> Z::m;
  std::vector<Z> A(N + 2);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    int B;
    std::cin >> B;
    A[i] -= B;
  }
  for (int i = N; i > 0; --i) {
    A[i] -= A[i - 1] + (i > 1 ? A[i - 2] : 0);
  }
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    cnt += A[i] == 0;
  }
  std::vector<Z> f(N + 2);
  f[0] = 0, f[1] = 1;
  for (int i = 2; i <= N + 1; ++i) {
    f[i] = f[i - 1] + f[i - 2];
  }
  auto update = [&](int i, char c, Z x) {
    if (c == 'B') {
      x *= -1;
    }
    if (i < N) {
      cnt -= A[i] == 0;
    }
    A[i] += x;
    if (i < N) {
      cnt += A[i] == 0;
    }
  };
  for (int q = 0; q < Q; ++q) {
    char c;
    int l, r;
    std::cin >> c >> l >> r;
    --l;
    update(l, c, 1);
    update(r, c, -f[r - l + 1]);
    update(r + 1, c, -f[r - l]);
    std::cout << (cnt == N ? "YES" : "NO") << '\n';
  }
  exit(0);
}