#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
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

const int N = 4096;

mint ways[2][N][2][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int p, a;
  string s;
  cin >> p >> a >> s;

  vector<int> x = {0};
  for (auto i : s) {
    int carry = 0;
    for (auto &j : x) {
      long long value = 10LL * j + carry;
      carry = value / p;
      j = value % p;
    }

    while (carry > 0) {
      x.push_back(carry % p);
      carry /= p;
    }

    carry = i - '0';
    for (auto &j : x) {
      int value = j + carry;
      carry = value / p;
      j = value % p;
    }

    while (carry > 0) {
      x.push_back(carry % p);
      carry /= p;
    }
  }

  ways[0][0][0][0] = ways[0][0][0][1] = 1;
  for (int i = 0; i < (int) x.size(); ++i) {
    for (int j = 0; j <= i; ++j) {
      ways[1 - i % 2][j][0][0] +=
        ((long long) p * (p + 1) / 2) * ways[i % 2][j][0][0] +
        ((long long) p * (p - 1) / 2) * ways[i % 2][j][1][0];

      ways[1 - i % 2][j + 1][1][0] +=
        ((long long) p * (p - 1) / 2) * ways[i % 2][j][0][0] +
        ((long long) p * (p + 1) / 2) * ways[i % 2][j][1][0];

      ways[1 - i % 2][j][0][1] +=
        ((long long) x[i] * (x[i] + 1) / 2) * ways[i % 2][j][0][0] +
        ((long long) x[i] * (x[i] - 1) / 2) * ways[i % 2][j][1][0] +
        (x[i] + 1) * ways[i % 2][j][0][1] +
        x[i] * ways[i % 2][j][1][1];

      ways[1 - i % 2][j + 1][1][1] +=
        ((long long) x[i] * (2 * p - x[i] - 1) / 2) * ways[i % 2][j][0][0] +
        ((long long) x[i] * (2 * p - x[i] + 1) / 2) * ways[i % 2][j][1][0] +
        (p - x[i] - 1) * ways[i % 2][j][0][1] +
        (p - x[i]) * ways[i % 2][j][1][1];

      for (int k = 0; k < 2; ++k) {
        for (int l = 0; l < 2; ++l) {
          ways[i % 2][j][k][l] = 0;
        }
      }
    }
  }

  mint ans = 0;
  for (int i = a; i <= (int) x.size(); ++i) {
    ans += ways[x.size() % 2][i][0][1];
  }

  cout << ans << "\n";
}