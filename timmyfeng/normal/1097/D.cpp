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
const int L = 64;

mint mod_inv[L];
mint ans = 1;
int m;

void process(long long p, int a) {
  vector<mint> pr(a + 1);
  pr[a] = 1;

  for (int j = 0; j < m; ++j) {
    vector<mint> pr_new(a + 1);
    for (int k = 0; k <= a; ++k) {
      for (int kk = 0; kk <= k; ++kk) {
        pr_new[kk] += pr[k] * mod_inv[k + 1];
      }
    }
    swap(pr, pr_new);
  }

  mint e = 0;
  for (int j = 0; j <= a; ++j) {
    e += mint(p).pow(j) * pr[j];
  }
  ans *= e;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n >> m;

  for (int i = 1; i < L; ++i) {
    mod_inv[i] = mint(i).inv();
  }


  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      int a = 0;
      while (n % i == 0) {
        ++a;
        n /= i;
      }
      process(i, a);
    }
  }

  if (n > 1) {
    process(n, 1);
  }

  cout << ans.val << "\n";
}