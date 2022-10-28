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
const int N = 1'000'000;
const int L = 6;

int mask[1 << L];
mint pow2[N];

mint square[N];
int size_s[N];
mint sum[N];
mint res[N];

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  pow2[0] = 1;
  mint inv2 = mint(2).inv();
  for (int i = 1; i <= n; ++i) {
    pow2[i] = pow2[i - 1] + pow2[i - 1];
  }

  for (int i = 0; i < (1 << L); ++i) {
    mask[i] = 0;
    for (int j = L - 1; j >= 0; --j) {
      mask[i] *= 10;
      if ((i & (1 << j)) > 0) {
        ++mask[i];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a, a + n);
  int ptr = n - 1;
  long long ans = 0;

  for (int i = N - 1; i >= 0; --i) {
    int bad = 0;
    for (int j = 0, k = i; j < L; ++j) {
      bad |= (k % 10 == 9) << j;
      k /= 10;
    }

    for (int j = 1; j < (1 << L); ++j) {
      if ((j & bad) == 0) {
        int c = (__builtin_parity(j) == 1) ? 1 : -1;
        square[i] += square[i + mask[j]] * c;
        size_s[i] += size_s[i + mask[j]] * c;
        sum[i] += sum[i + mask[j]] * c;
      }
    }

    while (ptr >= 0 && a[ptr] == i) {
      square[i] += (mint) i * i;
      sum[i] += i;
      ++size_s[i];
      --ptr;
    }

    res[i] = sum[i] * sum[i] + square[i];
    if (size_s[i] == 0) {
      res[i] *= inv2 * inv2;
    } else if (size_s[i] == 1) {
      res[i] *= inv2;
    } else {
      res[i] *= pow2[size_s[i] - 2];
    }

    mint g = 0;
    for (int j = 0; j < (1 << L); ++j) {
      if ((j & bad) == 0) {
        if (__builtin_parity(j) == 1) {
          g -= res[i + mask[j]];
        } else {
          g += res[i + mask[j]];
        }
      }
    }
    ans ^= (long long) g.val * i;
  }

  cout << ans << "\n";
}