#include <bits/stdc++.h>

template <int P>
struct Z {
  int x;
  Z() : x(0) {}
  Z(int64_t x_) {
    x = x_ % P;
    if (x < 0) x += P;
  }
  Z& operator+=(Z rhs) {
    x += rhs.x;
    if (x >= P) x -= P;
    return *this;
  }
  Z& operator-=(Z rhs) {
    x -= rhs.x;
    if (x < 0) x += P;
    return *this;
  }
  Z& operator*=(Z rhs) {
    x = int64_t(x) * rhs.x % P;
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

struct State {
  int last;
  Zp sum, cnt;
  State(int last, Zp sum, Zp cnt) : last(last), sum(sum), cnt(cnt) {}
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> a[i];
    }
    std::reverse(a.begin(), a.end());
    std::vector<State> dp;
    Zp ans = 0;
    for (int i = 0; i < N; ++i) {
      int x = a[i];
      std::vector<State> ndp;
      ndp.emplace_back(a[i], 0, 1);
      for (auto prev : dp) {
        int k = (x + prev.last - 1) / prev.last;
        State st(x / k, prev.sum + (k - 1) * prev.cnt, prev.cnt);
        if (!ndp.empty() && ndp.back().last == st.last) {
          ndp.back().sum += st.sum;
          ndp.back().cnt += st.cnt;
        } else {
          ndp.push_back(st);
        }
      }
      std::swap(dp, ndp);
      for (auto st : dp) {
        ans += st.sum;
      }
    }
    std::cout << ans << '\n';
  }
  exit(0);
}