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

template <typename T>
struct RootOfUnity;  // Not implemented for general T.

template <typename T>
class FFT {
public:
  static constexpr int maxN = 1 << 20;

  static std::vector<T> dft(std::vector<T> p) {
    return get_instance().transform(std::move(p), false);
  }
  static std::vector<T> idft(std::vector<T> p) {
    return get_instance().transform(std::move(p), true);
  }

private:
  static const FFT& get_instance() {
    static FFT fft(maxN);
    return fft;
  }

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
    for (int sgn : {+1, -1}) {
      root[0] = 1;
      for (int b = 2; b < N; b <<= 1) {
        T w = RootOfUnity<T>::root_of_unity(sgn * 2 * b);
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

  std::vector<T> transform(std::vector<T> p, bool inverse) const {
    int N = p.size();
    assert((N & (N - 1)) == 0 && N <= maxN);
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
    p.resize(K);
    q.resize(K);
    auto phat = FFT<T>::dft(std::move(p));
    auto qhat = FFT<T>::dft(std::move(q));
    for (int i = 0; i < K; ++i) {
      phat[i] *= qhat[i];
    }
    auto res = FFT<T>::idft(std::move(phat));
    res.resize(R);
    return res;
  }
}

constexpr int ntt_mod = 998244353;
template <>
struct RootOfUnity<Z<ntt_mod>> {
  static constexpr Z<ntt_mod> g = Z<ntt_mod>(3);
  static Z<ntt_mod> root_of_unity(int N) {
    return pow(g, int(ntt_mod - 1) / N);
  }
};

template <typename T>
T one_coeff(std::vector<T> p, std::vector<T> q, long long n) {
  int d = p.size();
  for (; n > 0; n >>= 1) {
    auto qsgn = q;
    for (int i = 1; i <= d; i += 2) {
      qsgn[i] *= -1;
    }
    auto u = p * qsgn, v = q * qsgn;
    int b = n & 1;
    for (int i = 0; i < d; ++i) {
      p[i] = u[i << 1 | b];
      q[i] = v[i << 1];
    }
    q[d] = v[d << 1];
  }
  return p[0] / q[0];
}

// Given the linear recurrence u[i+1] = c[0]u[i] + ... + c[d-1]u[i - (d - 1)] and the initial values u[0], ..., u[d-1],
// finds u[n].
// Time complexity: O(convolution(d) * log(n)).
template <typename T>
T solve_linear_recurrence(std::vector<T> c, std::vector<T> u, long long n) {
  assert(c.size() <= u.size());
  u.resize(c.size());
  if (n < u.size()) {
    return u[n];
  } else if (c.empty()) {
    return 0;
  }
  int d = c.size(); 
  std::vector<T> q(d + 1, 0);
  q[0] = 1;
  for (int i = 0; i < d; ++i) q[i + 1] -= c[i];
  auto p = u * q;
  p.resize(d);
  return one_coeff(p, q, n);
}

template <typename T>
std::vector<T> berlekamp_massey(const std::vector<T>& s) {
  std::vector<T> c, b = {0};
  for (int i = 0; i < s.size(); ++i) {
    T d = s[i];
    for (int j = 0; j < c.size(); ++j) {
      d -= c[j] * s[i - 1 - j];
    }
    bool length_change = false;
    std::vector<T> nb;
    if (d != 0) {
      if (c.size() < b.size()) {
        length_change = true;
        nb = c;
        c.insert(c.end(), b.size() - c.size(), 0);
      }
      for (int j = 0; j < b.size(); ++j) {
        c[j] += d * b[j];
      }
    }
    if (length_change) {
      T inv = 1 / d;
      for (int j = 0; j < nb.size(); ++j) {
        nb[j] *= -inv;
      }
      nb.insert(nb.begin(), inv);
      std::swap(b, nb);
    } else {
      b.insert(b.begin(), 0);
    }
  }
  return c;
}

#include <cstring>

using Zp = Z<998244353>;

constexpr int C2(int N) {
  return N * (N - 1) / 2;
}

constexpr int kmax = 11, xmax = 11, recurrence_size = C2(12) * C2(12);

Zp dp[kmax + 1][xmax + 1][kmax + 1][kmax + 1], next[kmax + 1][xmax + 1][kmax + 1][kmax + 1];

std::vector<Zp> ans[kmax + 1][xmax + 1], rec[kmax + 1][xmax + 1];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  dp[0][0][0][0] = 1;

  for (int n = 0; n < 2 * recurrence_size; ++n) {
    for (int k = 0; k <= kmax; ++k) {
      for (int x = 0; x <= k; ++x) {
        ans[k][x].push_back(dp[k][x][0][0]);

        for (int lt = 0; lt <= k; ++lt) {
          for (int need = lt; need <= kmax; ++need) {
            Zp cur = dp[k][x][lt][need];
            if (cur == 0) continue;
            for (int nlt = 0; nlt <= kmax - k; ++nlt) {
              int nk = k + nlt;
              int nx = x + (nlt < lt);
              int nneed = nlt < need ? need - 1 : nlt;
              if (nk <= kmax && nx <= xmax) {
                next[nk][nx][nlt][nneed] += cur;
              }
            }
          }
        }

      }
      for (int x = k + 1; x <= xmax; ++x) {
        ans[k][x].push_back(0);
      }
    }

    for (int k = 0; k <= kmax; ++k) {
      for (int x = 0; x <= k; ++x) {
        for (int lt = 0; lt <= k; ++lt) {
          for (int need = lt; need <= kmax; ++need) {
            dp[k][x][lt][need] = next[k][x][lt][need];
            next[k][x][lt][need] = 0;
          }
        }
      }
    }
  }

  for (int k = 0; k <= kmax; ++k) {
    for (int x = 0; x <= xmax; ++x) {
      rec[k][x] = berlekamp_massey(ans[k][x]);
      ans[k][x].resize(rec[k][x].size());
    }
  }

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, k, x;
    std::cin >> n >> k >> x;
    std::cout << solve_linear_recurrence(rec[k][x], ans[k][x], n) << '\n';
  }
  exit(0);
}