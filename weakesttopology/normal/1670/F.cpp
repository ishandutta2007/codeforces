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

template <typename T>
struct Combinatorics;

template <typename T>
const Combinatorics<T> combinatorics(1 << 20);

template <unsigned P>
struct Combinatorics<Z<P>> {
  std::vector<Z<P>> fact, rfact, r;

  Combinatorics(int N) : fact(N), rfact(N), r(N) {
    fact[0] = fact[1] = rfact[0] = rfact[1] = r[1] = 1;
    for (int i = 2; i < N; ++i) {
      r[i] = -(P / i * r[P % i]);
      rfact[i] = r[i] * rfact[i - 1];
      fact[i] = i * fact[i - 1];
    }
  }

  Z<P> C(int n, int k) const {
    return k < 0 || n < k ? 0 : fact[n] * rfact[k] * rfact[n - k];
  }

  Z<P> S(int n, int k) const {
    return k == 0 ? n == 0 : C(n + k - 1, k - 1);
  }
};

using Zp = Z<(int)1e9 + 7>;

Zp solve(int N, uint64_t R, uint64_t Z) {
  Zp unbounded = 0;
  std::vector<Zp> dp(2 * N);
  dp[0] = 1;
  for (int k = 63; k >= 0; --k) {
    if (R >> k & 1) {
      unbounded += dp[2 * N - 1];
      dp[2 * N - 1] = 0;
      std::rotate(dp.begin(), dp.end() - 1, dp.end());
    }
    std::vector<Zp> next(2 * N);
    for (int n = 0; n < 2 * N; ++n) {
      for (int l = Z >> k & 1; l <= n; l += 2) {
        next[n - l] += combinatorics<Zp>.C(N, l) * dp[n];
      }
    }
    Zp next_unbounded = 0;
    for (int l = Z >> k & 1; l <= N; l += 2) {
      next_unbounded += unbounded * combinatorics<Zp>.C(N, l);
    }
    std::fill(dp.begin(), dp.end(), 0);
    unbounded = next_unbounded;
    for (int n = 0; n < N; ++n) {
      dp[2 * n] += next[n];
      unbounded += next[N + n];
    }
  }
  return std::accumulate(dp.begin(), dp.end(), Zp()) + unbounded;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  uint64_t L, R, Z;
  std::cin >> N >> L >> R >> Z;
  std::cout << solve(N, R, Z) - solve(N, L - 1, Z) << '\n';
  exit(0);
}