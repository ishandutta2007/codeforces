#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
struct mint {

  int val = 0;

  mint() {}

  mint(int a) : val(a) {
    while (val < 0) {
      val += M;
    }
    while (val >= M) {
      val -= M;
    }
  }

  mint(long long a) : val(a % M) {
    if (val < 0) {
      val += M;
    }
  }

  mint operator+=(mint oth) {
    val += oth.val;
    val -= (val >= M) ? M : 0;
    return *this;
  }

  mint operator-=(mint oth) {
    val -= oth.val;
    val += (val < 0) ? M : 0;
    return *this;
  }

  mint operator*=(mint oth) {
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

  mint operator-() {
    mint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }

  friend mint operator+(mint a, mint b) {
    return mint(a) += b;
  }

  friend mint operator-(mint a, mint b) {
    return mint(a) -= b;
  }

  friend mint operator*(mint a, mint b) {
    return mint(a) *= b;
  }

  friend bool operator==(mint a, mint b) {
    return a.val == b.val;
  }

  friend bool operator!=(mint a, mint b) {
    return a.val != b.val;
  }

  friend ostream& operator<<(ostream &out, mint a) {
    out << a.val;
    return out;
  }

  friend mint pow(mint b, long long e = M - 2) {
    mint res = 1;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= b;
      }
      b *= b;
      e /= 2;
    }
    return res;
  }

};

const int N = 5000 + 1;

mint ways[N][N], coeff[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, q;
  cin >> n >> k >> q;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0) {
        ways[i][j] = 1;
      } else {
        if (j > 0) {
          ways[i][j] += ways[i - 1][j - 1];
        }
        if (j < n - 1) {
          ways[i][j] += ways[i - 1][j + 1];
        }
      }
    }
  }

  mint ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      coeff[i] += ways[j][i] * ways[k - j][i];
    }
    ans += a[i] * coeff[i];
  }

  while (q--) {
    int i, x;
    cin >> i >> x;
    ans += (x - a[i - 1]) * coeff[i - 1];
    cout << ans << "\n";
    a[i - 1] = x;
  }
}