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

using mint = modint<998244353>;
const int N = 100000 + 1;

vector<int> indices[N];
mint ans[N];
int freq[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int max_a = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> freq[i];
    max_a = max(max_a, a[i]);

    for (int j = 1; j * j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        indices[j].push_back(i);
        if (j * j < a[i]) {
          indices[a[i] / j].push_back(i);
        }
      }
    }
  }

  for (int i = max_a; i >= 1; --i) {
    mint sum = 0;
    long long count = 0;
    for (auto j : indices[i]) {
      sum += (mint) a[j] * freq[j];
      count += freq[j];
    }

    mint pow2 = (count >= 3) ? mint(2).pow(count - 3) : mint(2).inv().pow(3 - count);

    for (auto j : indices[i]) {
      ans[i] += (mint) freq[j] * (count - 1) * (pow2 * 2) * a[j] * a[j];
      if (count >= 2) {
        ans[i] += (mint) freq[j] * ((count - 2) * pow2 + pow2 * 2) * a[j] * (sum - a[j]);
      }
    }

    for (int j = 2 * i; j <= max_a; j += i) {
      ans[i] -= ans[j];
    }
  }

  cout << ans[1].val << "\n";
}