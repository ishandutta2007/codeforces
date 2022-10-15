#include <bits/stdc++.h>

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
  Z& operator/=(Z rhs) {
    return *this *= pow(rhs, -1);
  }
  Z operator-() const {
    return Z() - *this;
  }
  bool operator==(Z rhs) const {
    return value == rhs.value;
  }
  bool operator!=(Z rhs) const {
    return value != rhs.value;
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
    return out << a.value;
  }
  friend std::istream& operator>>(std::istream& in, Z& a) {
    long long value;
    in >> value;
    a = Z(value);
    return in;
  }
};

template <unsigned P>
Z<P> pow(Z<P> x, long long p) {
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
struct FFT {
  std::vector<int> revs;
  std::vector<T> roots;

  FFT(int N) : roots(2 * (N - 1)), revs(2 * N) {
    if (N == 1) return;
    int* rev = revs.data();
    for (int b = 1; b < N; b <<= 1) {
      int* nrev = rev + b;
      for (int i = 0; i < b; ++i) {
        nrev[i] = rev[i] << 1;
        nrev[i | b] = nrev[i] | 1;
      }
      rev = nrev;
    }
    T* root = roots.data();
    for (auto sgn : {+1, -1}) {
      root[0] = 1;
      for (int b = 2; b < N; b <<= 1) {
        T w = root_of_unity(sgn * 2 * b);
        T* nroot = root + (b >> 1);
        for (int i = 0; i < b; ++i) {
          nroot[i] = root[i >> 1];
          if (i & 1) {
            nroot[i] *= w;
          }
        }
        root = nroot;
      }
      root += N >> 1;
    }
  }

  static T root_of_unity(int N);  // Not implemented for general T.

  std::vector<T> operator()(int N, std::vector<T> p, bool inverse) const {
    p.resize(N);
    const int* rev = revs.data() + N - 1;
    for (int i = 0; i < N; ++i) {
      if (i < rev[i]) {
        std::swap(p[i], p[rev[i]]);
      }
    }
    const T* root = roots.data();
    if (inverse) {
      root += roots.size() / 2;
    }
    for (int b = 1; b < N; b <<= 1) {
      for (int s = 0; s < N; s += 2 * b) {
        for (int i = 0; i < b; ++i) {
          int u = s | i, v = u | b;
          T x = p[u], y = root[i] * p[v];
          p[u] = x + y;
          p[v] = x - y;
        }
      }
      root += b;
    }
    if (inverse) {
      T inv = T(1) / T(N);
      for (int i = 0; i < N; ++i) p[i] *= inv;
    }
    return p;
  }
};

template <typename T>
const FFT<T> fft(1 << 20);

constexpr int naive_threshold = 64;

template <typename T>
std::vector<T> operator*(std::vector<T> p, std::vector<T> q) {
  int N = p.size(), M = q.size();
  if (N == 0 || M == 0) {
    return {};
  } else if (std::min(N, M) <= naive_threshold) {
    std::vector<T> res(N + M - 1);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        res[i + j] += p[i] * q[j];
      }
    }
    return res;
  } else {
    int R = N + M - 1, K = 1;
    while (K < R) K <<= 1;
    auto phat = fft<T>(K, std::move(p), false), qhat = fft<T>(K, std::move(q), false);
    for (int i = 0; i < K; ++i) {
      phat[i] *= qhat[i];
    }
    auto res = fft<T>(K, std::move(phat), true);
    res.resize(R);
    return res;
  }
}

constexpr int ntt_mod = 998244353;
template <>
Z<ntt_mod> FFT<Z<ntt_mod>>::root_of_unity(int N) {
  static constexpr Z<ntt_mod> g = Z<ntt_mod>(3);
  return pow(g, int(ntt_mod - 1) / N);
}

template <typename T>
struct Combinatorics {};

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

using Zp = Z<ntt_mod>;
const auto& C = combinatorics<Zp>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<Zp> dp = {1};
  for (int i = 0; i < N; ++i) {
    int a, b;
    std::cin >> a >> b;
    int k = std::min(a, b), d = std::abs(a - b);
    if (a > b) {
      std::vector<Zp> p(d + 1);
      for (int l = 0; l <= d; ++l) {
        p[l] = C.C(d, l);
      }
      dp = p * dp;
    }
    int n = dp.size() - 1;
    std::vector<Zp> p(2 * n + 1);
    for (int d = -n; d <= n; ++d) {
      p[n + d] = C.C(2 * k, d + k);
    }
    dp = dp * p;
    dp.erase(dp.begin(), dp.begin() + n);
    dp.resize(n + 1);
    if (a < b) {
      std::vector<Zp> p(d + 1);
      for (int l = 0; l <= d; ++l) {
        p[l] = C.C(d, l);
      }
      dp = p * dp;
      dp.erase(dp.begin(), dp.begin() + d);
      dp.resize(n + 1 - d);
    }
  }
  Zp res = std::accumulate(dp.begin(), dp.end(), Zp());
  std::cout << res << '\n';
  exit(0);
}