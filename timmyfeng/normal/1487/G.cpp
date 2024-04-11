#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;
struct mint {

  int value;

  mint() : value(0) {}

  template <class T>
  mint(T x) {
    value = x % M;
    if (value < 0) {
      value += M;
    }
  }

  mint & operator++() {
    if (++value == M) {
      value = 0;
    }
    return *this;
  }

  mint & operator--() {
    if (--value == -1) {
      value = M - 1;
    }
    return *this;
  }

  mint operator++(int) {
    mint res = *this;
    ++*this;
    return res;
  }

  mint operator--(int) {
    mint res = *this;
    --*this;
    return res;
  }

  mint & operator+=(mint oth) {
    value += oth.value;
    if (value >= M) {
      value -= M;
    }
    return *this;
  }

  mint & operator-=(mint oth) {
    value -= oth.value;
    if (value < 0) {
      value += M;
    }
    return *this;
  }

  mint & operator*=(mint oth) {
    value = (long long) value * oth.value % M;
    return *this;
  }

  mint operator+() const {
    return *this;
  }

  mint operator-() const {
    return mint() - *this;
  }

  mint pow(long long e = M - 2) const {
    mint res = 1, b = *this;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= b;
      }
      b *= b;
      e /= 2;
    }
    return res;
  }

  friend mint operator+(mint a, mint b) {
    return a += b;
  }

  friend mint operator-(mint a, mint b) {
    return a -= b;
  }

  friend mint operator*(mint a, mint b) {
    return mint(a) *= b;
  }

  friend bool operator==(mint a, mint b) {
    return a.value == b.value;
  }

  friend bool operator!=(mint a, mint b) {
    return a.value != b.value;
  }

  friend ostream & operator<<(ostream &out, mint a) {
    out << a.value;
    return out;
  }

};

const int N = 400 + 1;
const int A = 26;

mint one[2][N][2][2], two[2][N][N][3][3];
int c[A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (auto &i : c) {
    cin >> i;
  }

  mint ans = mint(26).pow(2) * mint(25).pow(n - 2);

  one[0][0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < 2; ++k) {
        one[1 - i % 2][j][k][0] += (A - 2 + (i < 2)) * one[i % 2][j][0][k] + (A - 1) * one[i % 2][j][1][k];
        one[1 - i % 2][j + 1][k][1] += one[i % 2][j][0][k];
        one[i % 2][j][0][k] = one[i % 2][j][1][k] = 0;
      }
    }
  }

  two[0][0][0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        for (int l = 0; l < 3; ++l) {
          two[1 - i % 2][j][k][l][0] += (A - 3 + (i < 2)) * two[i % 2][j][k][0][l] +
            (A - 2) * (two[i % 2][j][k][1][l] + two[i % 2][j][k][2][l]);
          two[1 - i % 2][j + 1][k][l][1] += two[i % 2][j][k][0][l] + two[i % 2][j][k][2][l];
          two[1 - i % 2][j][k + 1][l][2] += two[i % 2][j][k][0][l] + two[i % 2][j][k][1][l];
          two[i % 2][j][k][0][l] = two[i % 2][j][k][1][l] = two[i % 2][j][k][2][l] = 0;
        }
      }
    }
  }

  for (int i = 0; i < A; ++i) {
    for (int j = c[i] + 1; j <= n; ++j) {
      for (int k = 0; k < 2; ++k) {
        for (int l = 0; l < 2; ++l) {
          ans -= one[n % 2][j][k][l];
        }
      }
    }
  }

  for (int i = 0; i < A; ++i) {
    for (int j = i + 1; j < A; ++j) {
      for (int k = c[i] + 1; k <= n; ++k) {
        for (int l = c[j] + 1; l <= n; ++l) {
          for (int u = 0; u < 3; ++u) {
            for (int v = 0; v < 3; ++v) {
              ans += two[n % 2][k][l][u][v];
            }
          }
        }
      }
    }
  }

  cout << ans << "\n";
}