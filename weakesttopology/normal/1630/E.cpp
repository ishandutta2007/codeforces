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

#include <map>
#include <cstring>

using Zp = Z<998244353>;

Zp fact(int n) {
  return n < 0 ? 0 : combinatorics<Zp>.fact[n];
}
Zp rfact(int n) {
  return n < 0 ? 0 : combinatorics<Zp>.rfact[n];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<int> cnt(N);
    for (int i = 0; i < N; ++i) {
      int a;
      std::cin >> a;
      --a;
      ++cnt[a];
    }
    int g = 0;
    std::map<int, int> freq;
    int uniq = 0;
    for (int x = 0; x < N; ++x) {
      if (cnt[x]) {
        ++uniq;
        g = std::gcd(g, cnt[x]);
        ++freq[cnt[x]];
      }
    }
    if (uniq == 1) {
      std::cout << "1\n";
      continue;
    }
    std::vector<Zp> P(N + 1), Q(N + 1);
    Zp A = 0, B = 0;
    for (int d = 1; d <= N; ++d) {
      int b = N / d;
      if (N % d || g % b) continue;
      int rem = d;
      Zp Qways = 1, Pways[2] = {1, 0};
      for (auto [c, f] : freq) {
        int q = c / b;
        Qways *= fact(rem);
        Qways *= pow(rfact(q), f);
        Qways *= rfact(rem - q * f);

        Zp nPways[2]{};
        nPways[0] += Pways[0] * fact(rem - 2) * pow(rfact(q), f) * rfact(rem - 2 - q * f);
        if (q >= 2) {
          nPways[1] += Pways[0] * f * fact(rem - 2) * pow(rfact(q), f - 1) * rfact(q - 2) * rfact(rem - 2 - q * (f - 1) - (q - 2));
        }
        nPways[1] += Pways[1] * fact(rem) * pow(rfact(q), f) * rfact(rem - q * f);
        std::memcpy(Pways, nPways, sizeof(Pways));

        rem -= q * f;
      }
      P[d] += N * Pways[1];
      Q[d] += Qways;
      for (int nd = 2 * d; nd <= N; nd += d) {
        int nb = N / nd;
        if (N % nd || g % nb) continue;
        P[nd] -= P[d];
        Q[nd] -= Q[d];
      }
      A += P[d] / d, B += Q[d] / d;
    }
    Zp E = N - A / B;
    std::cout << E << '\n';
  }
  exit(0);
}