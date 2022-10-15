#include <bits/stdc++.h>

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

template <typename T>
std::vector<T> p(const std::vector<T>& x) {
  std::vector<T> y(x.size());
  std::partial_sum(x.begin(), x.end(), y.begin());
  return y;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  int64_t K;
  std::cin >> N >> K;
  std::vector<int64_t> A(N);
  bool good = false;
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    if (A[i] >= K) {
      good = true;
    }
  }
  int l = 0;
  while (A[l] == 0) ++l;
  A.erase(A.begin(), A.begin() + l);
  N = A.size();
  int64_t cost = 0;
  if (!good) {
    if (N > 10) {
      while (*std::max_element(A.begin(), A.end()) < K) {
        A = p(A);
        ++cost;
      }
    } else {
      using F = __float128;
      Combinatorics<F> C(N + 1);
      std::vector<F> y(N);
      for (int k = 0; k < N; ++k) {
        y[k] = A.back();
        A = p(A);
      }
      constexpr F EPS = 1e-5;
      int64_t L = 0, R = K;
      while (L + 1 < R) {
        int64_t M = (L + R) / 2;
        F v = C.interpolate(y, M);
        (v < K && K - v >= EPS ? L : R) = M;
      }
      cost = R;
    }
  }
  std::cout << cost << '\n';
  exit(0);
}