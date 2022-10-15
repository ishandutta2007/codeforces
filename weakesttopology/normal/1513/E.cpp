#include <bits/stdc++.h>

template <int P>
struct Z {
  int x;
  Z() : x(0) {}
  Z(int64_t x_) {
    x = x_ % P;
    if (x < 0) x += P;
  }
  Z& operator+=(Z rhs) {
    x += rhs.x;
    if (x >= P) x -= P;
    return *this;
  }
  Z& operator-=(Z rhs) {
    x -= rhs.x;
    if (x < 0) x += P;
    return *this;
  }
  Z& operator*=(Z rhs) {
    x = int64_t(x) * rhs.x % P;
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
  T interpolate(const std::vector<T>& y, T x) {
    int n = y.size();
    pref[0] = suff[n - 1] = 1;
    for (int i = 0; i + 1 < n; ++i) {
      pref[i + 1] = pref[i] * (x - i);
    }
    for (int i = n - 1; i > 0; --i) {
      suff[i - 1] = suff[i] * (x - i);
    }
    T res = 0;
    for (int i = 0, sgn = (n % 2 ? +1 : -1); i < n; ++i, sgn *= -1) {
      res += y[i] * sgn * pref[i] * suff[i] * inv[i] * inv[n - 1 - i];
    }
    return res;
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
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  int64_t sum = 0;
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
    sum += a[i];
  }
  if (sum % N) {
    std::cout << "0\n";
  } else {
    int avg = sum / N;
    int lt = 0, eq = 0, gt = 0;
    for (int i = 0; i < N; ++i) {
      lt += a[i] < avg;
      eq += a[i] == avg;
      gt += a[i] > avg;
    }
    Combinatorics<Zp> C(N + 1);
    Zp ans = C.f[lt] * C.f[eq] * C.f[gt];
    if (eq > 0) {
      ans *= C.C(N, eq);
    }
    if (lt == 1) {
      ans *= gt + 1;
    } else if (gt == 1) {
      ans *= lt + 1;
    } else if (lt && gt) {
      ans *= 2;
    }
    std::map<int, int> f;
    for (int i = 0; i < N; ++i) {
      ++f[a[i]];
    }
    for (auto [k, v] : f) {
      ans *= C.inv[v];
    }
    std::cout << ans << '\n';
  }
  exit(0);
}