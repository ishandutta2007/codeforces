#include <bits/stdc++.h>
using namespace std;

template <int M>
struct modint {

  int val = 0;

  modint() {}

  modint(int a) : val(a) {
    while (val < 0) {
      val += M;
    }
    while (val >= M) {
      val -= M;
    }
  }

  modint(long long a) : val(a % M) {
    if (val < 0) {
      val += M;
    }
  }

  modint operator+=(modint oth) {
    val += oth.val;
    if (val >= M) {
      val -= M;
    }
    return *this;
  }

  modint operator-=(modint oth) {
    val -= oth.val;
    if (val < 0) {
      val += M;
    }
    return *this;
  }

  modint operator*=(modint oth) {
    val = 1LL * val * oth.val % M;
    return *this;
  }

  void operator++() {
    ++val;
    if (val == M) {
      val = 0;
    }
  }

  void operator--() {
    --val;
    if (val == -1) {
      val = M - 1;
    }
  }

  modint operator-() {
    modint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }

  int mod() {
    return M;
  }

  modint pow(int e) {
    modint base = val;
    modint res = 1;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= base;
      }
      base *= base;
      e /= 2;
    }
    return res;
  }

  modint inv() {
    return pow(M - 2);
  }

  friend modint operator+(modint a, modint b) {
    return modint(a) += b;
  }

  friend modint operator-(modint a, modint b) {
    return modint(a) -= b;
  }

  friend modint operator*(modint a, modint b) {
    return modint(a) *= b;
  }

  friend bool operator==(modint a, modint b) {
    return a.val == b.val;
  }

  friend bool operator!=(modint a, modint b) {
    return a.val != b.val;
  }

};

using mint = modint<998'244'353>;
const int N = 2'000 + 1;

mint choose[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t;
  cin >> n >> m >> t;

  choose[0][0] = 1;

  for (int i = 1; i <= n - 1; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0 || j == i) {
        choose[i][j] = 1;
      } else {
        choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
      }
    }
  }

  mint ans = choose[n - 1][t] * m * mint(m - 1).pow(t);

  cout << ans.val << "\n";
}