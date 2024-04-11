#include <iostream>
#include <numeric>
#include <vector>

struct Z;

Z pow(Z x, long long p);

struct Z {
  inline static unsigned P;
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

Z pow(Z x, long long p) {
  if (x == 0) {
    return p == 0 ? 1 : 0;
  }
  p %= Z::P - 1;
  if (p < 0) p += Z::P - 1;
  Z res = 1;
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
struct Combinatorics {
  std::vector<T> f, finv;

  Combinatorics(int N) : f(N), finv(N) {
    f[0] = finv[0] = 1;
    for (int i = 1; i < N; ++i) {
      f[i] = i * f[i - 1];
      finv[i] = 1 / f[i];
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N >> Z::P;

  std::vector<std::vector<int>> E(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  std::vector<std::vector<Z>> res(N, std::vector<Z>(N, 1));
  for (int u = 0; u < N; ++u) {
    res[u][0] = 0;
  }

  auto dfs = [&](auto& self, int u, int p) -> void {
    for (auto v : E[u]) {
      if (v == p) continue;
      self(self, v, u);
      for (int k = 1; k < N; ++k) {
        res[u][k] *= res[v][k];
      }
    }

    int deg = E[u].size();
    std::vector<std::vector<Z>> pref(deg, std::vector<Z>(N, 1)),
        suff(deg, std::vector<Z>(N, 1));
    for (int i = 0; i + 1 < deg; ++i) {
      int v = E[u][i];
      if (v == p) {
        pref[i + 1] = pref[i];
      } else {
        for (int k = 0; k < N; ++k) {
          pref[i + 1][k] = res[v][k] * pref[i][k];
        }
      }
    }
    for (int i = deg - 1; i > 0; --i) {
      int v = E[u][i];
      if (v == p) {
        suff[i - 1] = suff[i];
      } else {
        for (int k = 0; k < N; ++k) {
          suff[i - 1][k] = res[v][k] * suff[i][k];
        }
      }
    }

    for (int i = 0; i < deg; ++i) {
      int v = E[u][i];
      if (v == p) continue;
      Z sum = 0;
      for (int k = 1; k < N; ++k) {
        Z d = res[v][k] - res[v][k - 1];
        res[u][k] += d * sum;
        sum += pref[i][k] * suff[i][k];
      }
    }

    std::partial_sum(res[u].begin(), res[u].end(), res[u].begin());
  };

  std::vector<Z> A(N, 1);
  for (auto v : E[0]) {
    dfs(dfs, v, 0);
    for (int k = 0; k < N; ++k) {
      A[k] *= res[v][k];
    }
  }

  Combinatorics<Z> C(N);

  for (int k = 0; k < N; ++k) {
    A[k] *= C.finv[k];
  }

  std::vector<Z> B(N);
  for (int k = 0; k < N; ++k) {
    for (int l = 0, sgn = 1; k + l < N; ++l, sgn *= -1) {
      B[k + l] += A[k] * (sgn * C.finv[l]);
    }
  }

  for (int k = 1; k < N; ++k) {
    B[k] *= C.f[k];
    std::cout << B[k] << ' ';
  }
  std::cout << '\n';

  exit(0);
}