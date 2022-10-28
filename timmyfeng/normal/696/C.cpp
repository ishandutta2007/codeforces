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

struct matrix {

  mint a[2][2];

  matrix(mint u, mint v, mint w, mint x) {
    a[0][0] = u, a[0][1] = v;
    a[1][0] = w, a[1][1] = x;
  }

  void operator*=(matrix b) {
    matrix c = *this;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        a[i][j] = 0;
        for (int k = 0; k < 2; ++k) {
          a[i][j] += c.a[i][k] * b.a[k][j];
        }
      }
    }
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> k;

  mint den = 2;
  matrix num(0, 1, 2, 1);
  while (k--) {
    long long a;
    cin >> a;

    mint new_den = 1;
    matrix new_num(1, 0, 0, 1);
    while (a > 0) {
      if (a % 2 == 1) {
        new_num *= num;
        new_den *= den;
      }
      num *= num;
      den *= den;
      a /= 2;
    }

    num = new_num;
    den = new_den;
  }

  mint inv2 = pow((mint) 2);
  num *= matrix(-inv2, inv2, 1, 0);
  num *= matrix(-inv2, inv2, 1, 0);
  den *= inv2;

  cout << num.a[0][0] + num.a[0][1] << "/" << den << "\n";
}