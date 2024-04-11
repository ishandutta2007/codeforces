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

  modint operator+=(modint oth) {
    if (oth.val >= M) {
      exit(oth.val);
    }
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

using mint = modint<(119 << 23) + 1>;

const int N = 200'000 + 1;

mint pre_sum[N];
int d[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  sort(d, d + n);

  for (int i = 1; i <= n; ++i) {
    pre_sum[i] = pre_sum[i - 1] + d[i - 1];
  }

  while (m--) {
    int a, b;
    cin >> a >> b;

    int c = lower_bound(d, d + n, b) - d;
    if (a > n - c) {
      cout << 0 << "\n";
      continue;
    }

    mint strong = (n - c - a) * mint(n - c).inv() * (pre_sum[n] - pre_sum[c]);
    mint weak = (n - c - a + 1) * mint(n - c + 1).inv() * pre_sum[c];

    cout << (strong + weak).val << "\n";
  }
}