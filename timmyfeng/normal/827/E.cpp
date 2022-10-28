#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;
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

  modint pow(long long e) {
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

using mint = modint;

void ntt(vector<mint> &a) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; ++i) {
    int k = n / 2;
    while ((j & k) > 0) {
      j ^= k;
      k /= 2;
    }
    j ^= k;
 
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
 
  mint base = mint(3).pow((M - 1) / n);
  for (int len = 2; len <= n; len *= 2) {
    mint root = base.pow(n / len);
    for (int i = 0; i < n; i += len) {
      mint cur = 1;
      for (int j = 0; j < len / 2; ++j) {
        mint l = a[i + j];
        mint r = a[i + j + len / 2] * cur;
        a[i + j] = l + r;
        a[i + j + len / 2] = l - r;
        cur *= root;
      }
    }
  }
}
 
vector<mint> mul(const vector<mint> &u, const vector<mint> &v) {
  int n = 1;
  while (n < int(u.size() + v.size())) {
    n *= 2;
  }
 
  vector<mint> a(u.begin(), u.end());
  vector<mint> b(v.begin(), v.end());
  a.resize(n);
  b.resize(n);
  ntt(a);
  ntt(b);
 
  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  ntt(a);
 
  mint inv = mint(n).inv();
  for (mint &i : a) {
    i *= inv;
  }
  reverse(a.begin() + 1, a.end());
  return a;
}

void solve() {
  int n;
  string s;
  cin >> n >> s;

  vector<mint> v(n), k(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'V') {
      v[i] = 1;
    } else if (s[i] == 'K') {
      k[n - 1 - i] = 1;
    }
  }

  vector<bool> bad(n + 1);
  vector<mint> vk = mul(v, k);
  for (int i = 0; i < 2 * n; ++i) {
    if (vk[i] != 0) {
      bad[abs(n - 1 - i)] = true;
    }
  }

  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    bool good = true;
    for (int j = i; j <= n; j += i) {
      good &= !bad[j];
    }
    if (good) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}