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
const int N = 300 + 1;

mint dp[N];
mint dp_new[N];

mint fact[N];
mint inv_fact[N];

mint choose(int n, int k) {
  if (n < k) {
    return 0;
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  fact[0] = 1;
  inv_fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i;
    inv_fact[i] = fact[i].inv();
  }

  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    for (int j = 2; j * j <= a; ++j) {
      while (a % (j * j) == 0) {
        a /= j * j;
      }
    }
    ++cnt[a];
  }

  dp[0] = 1;
  int total = 1;
  for (auto [a, c] : cnt) {
    fill(dp_new, dp_new + total, 0);
    for (int i = 1; i <= min(c, total); ++i) {
      for (int j = 0; j <= i; ++j) {
        for (int k = j; k <= max(0, total - 2); ++k) {
          dp_new[k - j + c - i] += dp[k] * choose(total - k, i - j) * choose(k, j) * choose(c - 1, i - 1) * fact[c];
        }
      }
    }
    total += c;
    copy(dp_new, dp_new + total, dp);
  }

  cout << dp[0].val << "\n";
}