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

using mint = modint<1'000'000'007>;
const int N = 200'000;

mint fact[N];
mint a[N];

mint choose(int n, int k) {
  return fact[n] * fact[k].inv() * fact[n - k].inv();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[i] = mint(x);
  }

  if (n == 1) {
    cout << a[0].val << "\n";
    exit(0);
  }

  if (n % 2 == 1) {
    --n;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        a[i] = a[i] + a[i + 1];
      } else {
        a[i] = a[i] - a[i + 1];
      }
    }
  }

  fact[0] = 1;
  for (int i = 1; i < n / 2; ++i) {
    fact[i] = i * fact[i - 1];
  }

  mint left = 0;
  mint right = 0;

  for (int i = 0; i < n; ++i) {
    (i % 2 == 0 ? left : right) += choose(n / 2 - 1, i / 2) * a[i];
  }

  if (n % 4 == 2) {
    cout << (left + right).val << "\n";
  } else {
    cout << (left - right).val << "\n";
  }
}