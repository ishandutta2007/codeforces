#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

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
struct FormalPowerSeries : public std::vector<T> {
  using F = FormalPowerSeries;

  using std::vector<T>::vector;
  template <typename... Args>
  explicit FormalPowerSeries(Args&&... args) : std::vector<T>(std::forward<Args>(args)...) {}

  F operator+(const F& rhs) const {
    return F(*this) += rhs;
  }
  F& operator+=(const F& rhs) {
    if (this->size() < rhs.size()) {
      this->resize(rhs.size());
    }
    for (int i = 0; i < rhs.size(); ++i) {
      (*this)[i] += rhs[i];
    }
    return *this;
  }

  F operator-(const F& rhs) const {
    return F(*this) -= rhs;
  }
  F& operator-=(const F& rhs) {
    if (this->size() < rhs.size()) {
      this->resize(rhs.size());
    }
    for (int i = 0; i < rhs.size(); ++i) {
      (*this)[i] -= rhs[i];
    }
    return *this;
  }

  F operator*(T alpha) const {
    return F(*this) *= alpha;
  }
  F& operator*=(T alpha) {
    for (auto& x : *this) {
      x *= alpha;
    }
    return *this;
  }
  friend F operator*(T alpha, F rhs) {
    return rhs *= alpha;
  }

  F operator/(T alpha) const {
    return F(*this) *= 1 / alpha;
  }
  F& operator/=(T alpha) {
    return *this *= 1 / alpha;
  }

  F operator-() const {
    return F() -= *this;
  }

  F operator*(const F& rhs) const {
    return F(::operator*<T>(*this, rhs));
  }
  F& operator*=(const F& rhs) {
    return *this = *this * rhs;
  }

  F operator/(F d) const {
    assert(!d.empty() && d.back() != 0);
    int N = this->size(), M = d.size();
    if (N < M) {
      return {};
    } else if (M <= naive_threshold) {
      return naive_division(d).first;
    } else {
      int K = N - M + 1;
      std::reverse(d.begin(), d.end());
      d.resize(K);
      auto res = F(this->rbegin(), this->rbegin() + K) * inv(d);
      res.resize(K);
      std::reverse(res.begin(), res.end());
      return res;
    }
  }
  F& operator/=(const F& rhs) {
    return *this = *this / rhs;
  }

  F operator%(const F& rhs) const {
    return euclidean_division(rhs).second;
  }
  F operator%=(const F& rhs) {
    return *this = euclidean_division(rhs)->second;
  }

  std::pair<F, F> naive_division(const F& d) const {
    assert(!d.empty() && d.back() != 0);
    F q, r = *this;
    while (r.size() >= d.size()) {
      T c = r.back() / d.back();
      q.push_back(c);
      for (int i = 0; i < d.size(); ++i) {
        r.rbegin()[i] -= c * d.rbegin()[i];
      }
      r.pop_back();
    }
    std::reverse(q.begin(), q.end());
    return std::pair(q, r);
  }
  std::pair<F, F> euclidean_division(const F& d) const {
    assert(!d.empty() && d.back() != 0);
    if (d.size() <= naive_threshold) {
      return naive_division(d);
    } else {
      auto q = *this / d;
      F q0(q.begin(), q.begin() + std::min(q.size(), d.size()));
      auto r = *this - d * q0;
      r.resize(d.size() - 1);
      return std::pair(q, r);
    }
  }

  T operator()(T x) const {
    T pow = 1, y = 0;
    for (auto c : *this) {
      y += c * pow;
      pow *= x;
    }
    return y;
  }

  // Returns composition modulo x^M.
  // Time complexity: O(sqrt(N) * M * log(M)).
  F operator()(const F& g) const {
    int N = this->size(), M = g.size();
    int block_size = 1;
    while ((block_size + 1) * (block_size + 1) <= N) ++block_size;
    std::vector<F> pow(block_size);
    pow[0] = {1};
    for (int k = 0; k + 1 < block_size; ++k) {
      pow[k + 1] = pow[k] * g;
      pow[k + 1].resize(M);
    }
    F h = pow.back() * g;
    h.resize(M);
    F offset = {1}, res;
    for (int i = 0; i < N; i += block_size) {
      F p;
      for (int k = 0; k < block_size && i + k < N; ++k) {
        p += (*this)[i + k] * pow[k];
      }
      p.resize(M);
      res += offset * p;
      offset *= h;
      offset.resize(M);
    }
    res.resize(M);
    return res;
  }

  int val() const {
    auto iter = this->begin();
    while (iter != this->end() && *iter == 0) {
      ++iter;
    }
    return iter - this->begin();
  }

  void trim_left() {
    this->erase(this->begin(), this->begin() + val());
  }
  void trim_right() {
    while (!this->empty() && this->back() == 0) {
      this->pop_back();
    }
  }
};

template <typename T>
FormalPowerSeries<T> product(FormalPowerSeries<T>* p, int N) {
  if (N == 0) {
    return {1};
  } else if (N == 1) {
    return *p;
  } else {
    int h = N / 2;
    return product(p, h) * product(p + h, N - h);
  }
}

template <typename T>
FormalPowerSeries<T> inv(const FormalPowerSeries<T>& P) {
  using F = FormalPowerSeries<T>;
  assert(!P.empty() && P[0] != 0);
  F Q = {1 / P[0]};
  int N = P.size(), K = 1;
  while (K < N) {
    K *= 2;
    auto Qhat = fft<T>(2 * K, std::move(Q), false);
    auto Phat = fft<T>(2 * K, F(P.begin(), P.begin() + std::min(K, N)), false);
    for (int i = 0; i < 2 * K; ++i) {
      Qhat[i] *= 2 - Phat[i] * Qhat[i];
    }
    auto nQ = fft<T>(2 * K, Qhat, true);
    Q.swap(nQ);
    Q.resize(K);
  }
  Q.resize(N);
  return Q;
}

template <typename T>
FormalPowerSeries<T> D(FormalPowerSeries<T> P) {
  if (P.empty()) {
    return P;
  }
  for (int i = 0; i + 1 < P.size(); ++i) {
    P[i] = (i + 1) * P[i + 1];
  }
  P.pop_back();
  return P;
}

template <typename T>
FormalPowerSeries<T> I(FormalPowerSeries<T> P) {
  int N = P.size();
  P.push_back(0);
  for (int i = N - 1; i >= 0; --i) {
    P[i + 1] = P[i] / (i + 1);
  }
  P[0] = 0;
  return P;
}

template <typename T>
FormalPowerSeries<T> log(const FormalPowerSeries<T>& P) {
  assert(!P.empty() && P[0] == 1);
  int N = P.size();
  auto r = D(P) * inv(P);
  r.resize(N - 1);
  return I(std::move(r));
}

template <typename T>
FormalPowerSeries<T> exp(const FormalPowerSeries<T>& P) {
  assert(P.empty() || P[0] == 0);
  FormalPowerSeries<T> Q = {1};
  int N = P.size(), K = 1;
  while (K < N) {
    K *= 2;
    Q.resize(K);
    auto B = -log(Q);
    B[0] += 1;
    for (int i = 0; i < std::min(N, K); ++i) {
      B[i] += P[i];
    }
    Q *= B;
    Q.resize(K);
  }
  Q.resize(N);
  return Q;
}

template <typename T>
FormalPowerSeries<T> pow(const FormalPowerSeries<T>& P, T alpha) {
  assert(!P.empty() && P[0] == 1);
  return exp(alpha * log(P));
}

using Zp = Z<998244353>;
using fps = FormalPowerSeries<Zp>;

struct DSU {
  std::vector<int> p, rk;
  DSU(int N) : p(N), rk(N) {
    std::iota(p.begin(), p.end(), 0);
  }
  int find(int u) {
    return p[u] == u ? u : p[u] = find(p[u]);
  }
  void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (rk[u] < rk[v]) {
      std::swap(u, v);
    }
    p[v] = u, rk[u] += (rk[u] == rk[v]);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M, K;
  std::cin >> N >> M >> K;
  std::vector<int> p(K, -1), invp(K, -1), indeg(K);
  std::vector<bool> vis(K);
  DSU dsu(K + 1);
  for (int i = 0; i < N; ++i) {
    int c;
    std::cin >> c;
    std::vector<int> a(c);
    for (auto& x : a) {
      std::cin >> x;
      --x;
    }
    for (int i = 0; i + 1 < c; ++i) {
      int u = a[i], v = a[i + 1];
      if ((p[u] != -1 && p[u] != v) || (invp[v] != -1 && invp[v] != u)) {
        for (auto x : a) {
          dsu.unite(x, K);
        }
        break;
      }
      dsu.unite(u, v);
      p[u] = v;
      invp[v] = u;
      ++indeg[v];
    }
  }
  fps C(M + 1);
  for (int u = 0; u < K; ++u) {
    if (invp[u] != -1 || dsu.find(u) == dsu.find(K)) continue;
    int sz = 0;
    bool cycle = false;
    for (int v = u; v != -1; v = p[v]) {
      if (vis[v]) {
        cycle = true;
        break;
      }
      vis[v] = true;
      ++sz;
    }
    if (!cycle) {
      C[sz] += 1;
    }
  }
  Zp res = inv(fps{1} - C)[M];
  std::cout << res << '\n';
  exit(0);
}