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
    val -= (val >= M) ? M : 0;
    return *this;
  }

  modint operator-=(modint oth) {
    val -= oth.val;
    val += (val < 0) ? M : 0;
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

using mint = modint<998244353>;

const int N = 1 << 16;
const int K = 16 + 1;

mint choose[K][K];
mint ways[K][N];
mint ans[N];

array<int, 2> number[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < K; ++i) {
    choose[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }

  int n, l, c;
  cin >> n >> l >> c;

  int initial = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    initial ^= a;

    int delta = 0;
    for (int j = 0; j <= l; ++j) {
      delta = max(delta, (a ^ (a - j)) / 2);
    }

    int b = 1;
    while (b <= delta) {
      b *= 2;
    }

    number[i] = {b, a};
  }
  sort(number, number + n);

  ways[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    auto [b, a] = number[i];
    for (int j = l - 1; j >= 0; --j) {
      for (int jj = 1; j + jj <= l; ++jj) {
        for (int k = 0; k < b; ++k) {
          int delta = (a ^ (a - jj)) / 2;
          ways[j + jj][k ^ delta] += ways[j][k] * choose[l - j][jj];
        }
      }
    }
  }

  mint total = 0;
  for (int i = 0; i < (1 << (c - 1)); ++i) {
    total += ways[l][i];
  }
  total = total.inv();

  for (int i = 0; i < (1 << (c - 1)); ++i) {
    ans[(i * 2) ^ (l % 2) ^ initial] = ways[l][i] * total;
  }

  for (int i = 0; i < (1 << c); ++i) {
    cout << ans[i].val << " ";
  }
}