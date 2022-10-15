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

#include <deque>

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

  F operator*(F rhs) const {
    return F(::operator*<T>(*this, std::move(rhs)));
  }

  F& operator*=(F rhs) {
    return *this = F(::operator*<T>(std::move(*this), std::move(rhs)));
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
    return std::pair(std::move(q), std::move(r));
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
      return std::pair(std::move(q), std::move(r));
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

  void trim_left() {
    this->erase(this->begin(), this->begin() + val(*this));
  }

  void trim_right() {
    while (!this->empty() && this->back() == 0) {
      this->pop_back();
    }
  }
};

template <typename T>
int deg(const FormalPowerSeries<T>& P) {
  auto iter = std::find_if(P.rbegin(), P.rend(), [](T c) { return c != 0; });
  return int(P.size() - (iter - P.rbegin())) - 1;
}

template <typename T>
int val(const FormalPowerSeries<T>& P) {
  auto iter = std::find_if(P.begin(), P.end(), [](T c) { return c != 0; });
  return iter - P.begin();
}

template <typename T>
FormalPowerSeries<T> product(const FormalPowerSeries<T>* p, int N) {
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
  std::vector<T> Q = {1 / P[0]};
  int N = P.size(), K = 1;
  while (K < N) {
    K *= 2;
    Q.resize(2 * K);
    auto Qhat = FFT<T>::dft(std::move(Q));
    F P0(2 * K);
    std::copy_n(P.begin(), std::min(K, N), P0.begin());
    auto Phat = FFT<T>::dft(std::move(P0));
    for (int i = 0; i < 2 * K; ++i) {
      Qhat[i] *= 2 - Phat[i] * Qhat[i];
    }
    Q = FFT<T>::idft(std::move(Qhat));
    Q.resize(K);
  }
  Q.resize(N);
  return F(Q);
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

// Returns P^alpha mod x^N.
// Time complexity: O(N * M).
template <typename T>
FormalPowerSeries<T> slow_pow(const FormalPowerSeries<T>& P, T alpha, int N) {
  assert(!P.empty() && P[0] == 1);
  int M = P.size();
  auto dP = D(P);
  FormalPowerSeries<T> Q(N), dQ(N - 1);
  Q[0] = 1;
  for (int i = 0; i + 1 < N; ++i) {
    for (int j = 0; j < M - 1 && j <= i; ++j) {
      dQ[i] += dP[j] * Q[i - j];
    }
    dQ[i] *= alpha;
    for (int j = 1; j < M && j <= i; ++j) {
      dQ[i] -= P[j] * dQ[i - j];
    }
    Q[i + 1] = dQ[i] / (i + 1);
  }
  return Q;
}

// Returns composition f(g(x)) modulo x^M.
// Time complexity: O(N * M).
template <typename T>
FormalPowerSeries<T> composition(const FormalPowerSeries<T>& f, const FormalPowerSeries<T>& g) {
  using F = FormalPowerSeries<T>;
  int N = f.size(), M = g.size();
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
      p += f[i + k] * pow[k];
    }
    p.resize(M);
    res += offset * p;
    offset *= h;
    offset.resize(M);
  }
  res.resize(M);
  return res;
}

template <typename T>
struct Interpolator {
  using F = FormalPowerSeries<T>;
  struct Node {
    F P;
    T y;
    Node* left = nullptr;
    Node* right = nullptr;
  };
  std::deque<Node> deq;

  template <typename Iterator>
  Interpolator(Iterator first, Iterator last) {
    Node* root = &deq.emplace_back();
    build(root, first, last);
  }
  template <typename Iterator>
  void build(Node* node, Iterator first, Iterator last) {
    int len = last - first;
    if (len == 1) {
      node->P = {-first[0], 1};
    } else {
      node->left = &deq.emplace_back();
      node->right = &deq.emplace_back();
      Iterator middle = first + len / 2;
      build(node->left, first, middle);
      build(node->right, middle, last);
      node->P = node->left->P * node->right->P;
    }
  }

  std::vector<T> res;
  std::vector<T> evaluate(const F& Q) {
    res.clear();
    evaluate_aux(&deq[0], Q % deq[0].P);
    return std::move(res);
  }
  void evaluate_aux(Node* node, const F& Q) {
    if (node->left) {
      for (auto next : {node->left, node->right}) {
        evaluate_aux(next, Q % next->P);
      }
    } else {
      assert(Q.size() == 1);
      res.push_back(Q[0]);
    }
  }

  bool initiliazed = false;
  template <typename Iterator>
  F interpolate(Iterator first, Iterator last) {
    if (!initiliazed) {
      auto y = evaluate(D(deq[0].P));
      auto iter = y.begin();
      for (auto& node : deq) {
        if (node.left) continue;
        node.y = *iter;
        ++iter;
      }
      initiliazed = true;
    }
    return interpolate_aux(&deq[0], first, last);
  }
  template <typename Iterator>
  F interpolate_aux(Node* node, Iterator first, Iterator last) {
    int len = last - first;
    if (len == 1) {
      return {first[0] / node->y};
    } else {
      Iterator middle = first + len / 2;
      return node->right->P * interpolate_aux(node->left, first, middle) +
        node->left->P * interpolate_aux(node->right, middle, last);
    }
  }
};

template <typename T>
FormalPowerSeries<T> exp(T alpha, int N) {
  FormalPowerSeries<T> f(N);
  T pow = 1;
  for (int k = 0; k < N; ++k) {
    f[k] = pow * combinatorics<T>.rfact[k];
    pow *= alpha;
  }
  return f;
}

// Maps x^k -> x^k / k!.
template <typename T>
FormalPowerSeries<T> borel(FormalPowerSeries<T> P) {
  std::transform(P.begin(), P.end(), std::begin(combinatorics<T>.rfact), P.begin(),
      std::multiplies<T>());
  return P;
}

// Maps x^k -> k! * x^k.
template <typename T>
FormalPowerSeries<T> inv_borel(FormalPowerSeries<T> P) {
  std::transform(P.begin(), P.end(), std::begin(combinatorics<T>.fact), P.begin(),
      std::multiplies<T>());
  return P;
}

// Returns p(D)f.
template <typename T>
FormalPowerSeries<T> apply_polynomial_of_derivative(
    FormalPowerSeries<T> p, FormalPowerSeries<T> f) {
  int N = f.size();
  if (p.size() > N) {
    p.resize(N);
  }
  std::reverse(p.begin(), p.end());
  auto res = p * inv_borel(std::move(f));
  res.erase(res.begin(), res.begin() + p.size() - 1);
  return borel(std::move(res));
}

// Returns the polynomial that sends x -> P(x + c).
template <typename T>
FormalPowerSeries<T> taylor_shift(FormalPowerSeries<T> P, T c) {
  int N = P.size();
  return apply_polynomial_of_derivative(exp(c, N), std::move(P));
}

// FormalPowerSeries here are assumed to be given in the basis of falling factorials.
namespace falling_factorials {

template <typename T>
FormalPowerSeries<T> taylor_shift(FormalPowerSeries<T> P, T c) {
  int N = P.size();
  return apply_polynomial_of_derivative(slow_pow<T>({1, 1}, c, N), std::move(P));
}

// Returns the unique polynomial P of degree < N with P(i) = y[i].
template <typename T>
FormalPowerSeries<T> interpolate(FormalPowerSeries<T> y) {
  int N = y.size();
  auto P = exp(T(-1), N) * borel(std::move(y));
  P.resize(N);
  return P;
}

// Inverse of the above transformation.
template <typename T>
FormalPowerSeries<T> evaluate(FormalPowerSeries<T> P) {
  int N = P.size();
  auto y = exp(T(1), N) * std::move(P);
  y.resize(N);
  return inv_borel(std::move(y));
}

}  // namespace falling_factorials

// Returns P(c + j) for j = 0, ..., M - 1, where P is the unique polynomial of degree < N with
// P(i) = y[i].
template <typename T>
FormalPowerSeries<T> shift_of_sampling_points(FormalPowerSeries<T> y, T c, int M) {
  int N = y.size();
  auto P = falling_factorials::interpolate(std::move(y));
  P = falling_factorials::taylor_shift(std::move(P), c);
  P.resize(M);
  return falling_factorials::evaluate(std::move(P));
}

constexpr int ntt_mod = 998244353;
template <>
struct RootOfUnity<Z<ntt_mod>> {
  static constexpr Z<ntt_mod> g = Z<ntt_mod>(3);
  static Z<ntt_mod> root_of_unity(int N) {
    return pow(g, int(ntt_mod - 1) / N);
  }
};

using Zp = Z<998244353>;
using fps = FormalPowerSeries<Zp>;

struct DP {
  // A = taken, B = not taken
  fps dead, alive;
  DP operator+(const DP& rhs) const {
    return {dead + rhs.dead, alive + rhs.alive};
  }
  DP operator*(const DP& rhs) const {
    DP res;
    res.dead = dead * rhs.alive + alive * rhs.dead;
    res.alive = alive * rhs.alive;
    return res;
  }
};

struct SuffDP {
  DP prod, pref, suff;
  fps dead;
  SuffDP operator*(const SuffDP& rhs) const {
    SuffDP res;
    res.prod = prod * rhs.prod;
    res.pref = pref + prod * rhs.pref;
    res.suff = suff * rhs.prod + rhs.suff;
    res.dead = dead + rhs.dead + (suff * rhs.pref).dead;
    return res;
  }
};

SuffDP product(const SuffDP* p, int N) {
  if (N == 1) {
    return *p;
  }
  int h = N / 2;
  return product(p, h) * product(p + h, N - h);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, K;
  Zp X;
  std::cin >> N >> K >> X;
  std::vector<long long> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
    a[i] += 1;
  }
  fps zK(K + 1);
  zK[K] = 1;
  auto p = apply_polynomial_of_derivative(inv(fps{1} - X * exp(Zp(1), K + 1)), zK);
  auto p1 = p(1);
  auto ys = Interpolator<Zp>(a.begin(), a.end()).evaluate(p);
  std::vector<SuffDP> f;
  for (int i = 0; i < N; ++i) {
    Zp taking = X * p1 - pow(X, a[i]) * ys[i];
    DP v{{0, taking}, {1, a[i] - 1}};
    f.push_back(SuffDP{v, v, v, v.dead});
  }
  auto prod = product(f.data(), N);
  std::cout << D(prod.dead)(1) << '\n';
  exit(0);
}