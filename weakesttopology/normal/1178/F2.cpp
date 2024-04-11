#include <bits/stdc++.h>

template <uint32_t P>
struct Z {
  uint32_t x;
  Z() : x(0) {}
  Z(int64_t x_) {
    x_ %= P;
    if (x_ < 0) x_ += P;
    x = x_;
  }
  Z& operator+=(Z rhs) {
    x += rhs.x;
    if (x >= P) x -= P;
    return *this;
  }
  Z& operator-=(Z rhs) {
    x += P - rhs.x;
    if (x >= P) x -= P;
    return *this;
  }
  Z& operator*=(Z rhs) {
    x = uint64_t(x) * rhs.x % P;
    return *this;
  }
  Z& operator/=(Z rhs) {
    return *this *= rhs.power(-1);
  }
  Z power(int64_t p) const {
    p %= P - 1;
    if (p < 0) p += P - 1;
    Z res = 1;
    for (Z y = *this; p; p >>= 1, y *= y) {
      if (p & 1) res *= y;
    }
    return res;
  }
  Z operator-() const {
    return Z() - *this;
  }
  bool operator==(Z rhs) const {
    return x == rhs.x;
  }
  bool operator!=(Z rhs) const {
    return x != rhs.x;
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
    return out << a.x;
  }
  friend std::istream& operator>>(std::istream& in, Z& a) {
    int64_t x;
    in >> x;
    a = Z(x);
    return in;
  }
};
using Zp = Z<998244353>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  std::vector<int> c(M);
  for (int j = 0; j < M; ++j) {
    std::cin >> c[j];
    --c[j];
  }
  c.erase(std::unique(c.begin(), c.end()), c.end());
  M = c.size();
  if (M > 2 * N) {
    std::cout << "0\n";
    exit(0);
  }
  std::vector<int> first(N, -1), last(N);
  for (int j = 0; j < M; ++j) {
    int x = c[j];
    last[x] = j;
    if (first[x] == -1) {
      first[x] = j;
    }
  }
  std::vector dp(M + 1, std::vector<Zp>(M + 1));
  for (int i = 0; i <= M; ++i) {
    dp[i][i] = 1;
  }
  for (int len = 1; len <= M; ++len) {
    for (int l = 0, r = len; r <= M; ++l, ++r) {
      bool good = true;
      for (int j = l; j < r; ++j) {
        int y = c[j];
        if (!(l <= first[y] && last[y] < r)) {
          good = false;
          break;
        }
      }
      if (!good) continue;
      int x = *std::min_element(c.begin() + l, c.begin() + r);
      std::vector<int> pos;
      for (int j = l; j < r; ++j) {
        if (c[j] == x) {
          pos.push_back(j);
        }
      }
      int K = pos.size();
      Zp mid = 1;
      for (int k = 0; k + 1 < K; ++k) {
        mid *= dp[pos[k] + 1][pos[k + 1]];
      }
      Zp pref = 0;
      for (int j = l; j <= pos[0]; ++j) {
        pref += dp[l][j] * dp[j][pos[0]];
      }
      Zp suff = 0;
      for (int j = pos.back(); j < r; ++j) {
        suff += dp[pos.back() + 1][j + 1] * dp[j + 1][r];
      }
      dp[l][r] = pref * mid * suff;
    }
  }
  std::cout << dp[0][M] << '\n';
  exit(0);
}