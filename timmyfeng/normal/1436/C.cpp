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

using mint = modint<1000000007>;
const int N = 1000 + 1;

mint fact[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x, pos;
  cin >> n >> x >> pos;

  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i;
  }

  int lo = 0;
  int hi = n;

  int less = 0;
  int greater = 0;

  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (mid <= pos) {
      ++less;
      lo = mid + 1;
    } else {
      ++greater;
      hi = mid;
    }
  }

  if (x < less) {
    cout << 0 << "\n";
    exit(0);
  }

  if (n - x < greater) {
    cout << 0 << "\n";
    exit(0);
  }

  cout << (fact[x - 1] * fact[x - less].inv() * fact[n - x] * fact[n - x - greater].inv() * fact[n - less - greater]).val << "\n";
}