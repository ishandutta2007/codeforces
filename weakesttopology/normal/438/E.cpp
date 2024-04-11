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

using Zp = Z<ntt_mod>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  std::vector<Zp> C;
  for (int i = 0; i < N; ++i) {
    int c;
    std::cin >> c;
    if (C.size() <= c) {
      C.resize(c + 1);
    }
    C[c] = 1;
  }
  std::vector<Zp> F(M + 1), G(M + 1);
  F[0] = G[0] = 1;
  auto solve = [&](auto& self, int l, int r) -> void {
    if (r - l == 1) {
      if (l > 0) {
        G[l] += F[l] * F[0];
      }
    } else {
      int m = (l + r + 1) / 2;
      self(self, l, m);
      std::vector<Zp> A(G.begin() + l, G.begin() + m);
      std::vector<Zp> B(C.begin(), C.begin() + std::min<int>(C.size(), r - l));
      auto f = A * B;
      for (int i = m - l; i < r - l && i < f.size(); ++i) {
        F[l + i] += f[i];
      }
      std::vector<Zp> D(F.begin(), F.begin() + std::min(m, r - l));
      std::vector<Zp> E(F.begin() + l, F.begin() + m);
      auto g = D * E;
      for (int i = m - l; i < r - l && i < g.size(); ++i) {
        G[l + i] += g[i];
      }
      for (int i = l; i < m; ++i) {
        F[i] *= 2;
      }
      self(self, m, r);
      for (int i = l; i < m; ++i) {
        F[i] *= (ntt_mod + 1) / 2;
      }
    }
  };
  solve(solve, 0, M + 1);
  for (int j = 1; j <= M; ++j) {
    std::cout << F[j] << '\n';
  }
  exit(0);
}