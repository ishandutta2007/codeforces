#include <bits/stdc++.h>
template <typename T>
T extended_gcd(T a, T b, T& x, T& y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  } else {
    T q = b / a, r = b % a;
    T g = extended_gcd(r, a, y, x);
    x -= q * y;
    return g;
  }
}
template <typename T>
bool diophantine(T a, T b, T c, T& x, T& y) {
  T g = extended_gcd<T>(abs(a), abs(b), x, y);
  if (c % g) return false;
  x *= c / g;
  y *= c / g;
  if (a < 0) x *= -1;
  if (b < 0) y *= -1;
  return true;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  std::vector<int> p(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> p[i];
  }
  std::sort(p.begin(), p.end());
  auto check = [&](int x) {
    return !std::binary_search(p.begin(), p.end(), x);
  };
  std::vector<int> dp(M), next(M, -1);
  for (int g = M - 1; g >= 1; --g) {
    if (M % g) continue;
    int add = 0;
    for (int m = g; m < M; m += g) {
      if (std::gcd(m, M) == g) {
        add += check(m);
      } else if (dp[g] < dp[m]) {
        dp[g] = dp[m];
        next[g] = m;
      }
    }
    dp[g] += add;
  }
  std::vector<int> ans;
  int s = std::max_element(dp.begin(), dp.end()) - dp.begin();
  if (s != 0) {
    int prod = 1;
    for (int g = s; g != -1; g = next[g]) {
      for (int m = g; m < M; m += g) {
        if (std::gcd(m, M) == g && check(m)) {
          int64_t x, y;
          assert(diophantine<int64_t>(prod, M, m, x, y));
          prod = m;
          x %= M;
          x += M;
          x %= M;
          ans.push_back(x);
        }
      }
    }
  }
  assert(ans.size() == dp[s]);
  if (N == 0 || p[0] != 0) {
    ans.push_back(0);
  }
  std::cout << ans.size() << '\n';
  for (auto x : ans) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  exit(0);
}