#include <bits/stdc++.h>
using namespace std;

// each ordered k-sequence contributes 2 ^ #(of unincluded elements)

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

mint ways[N], fact[N], inv[N], choose[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < N; ++i) {
    choose[i][0] = choose[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }

  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i;
  }

  for (int i = 1; i < N; ++i) {
    inv[i] = pow((mint) i);
  }

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= k; ++i) {
    ways[i] = pow(mint(i), k);
    for (int j = 1; j < i; ++j) {
      ways[i] -= choose[i][j] * ways[j];
    }
  }

  mint ans = 0;
  for (int i = 1; i <= min(n, k); ++i) {
    mint coeff = 1;
    for (int j = 0; j < i; ++j) {
      coeff *= n - j;
      coeff *= inv[j + 1];
    }
    ans += coeff * ways[i] * pow((mint) 2, n - i);
  }

  cout << ans << "\n";
}