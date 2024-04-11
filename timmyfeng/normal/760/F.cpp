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
const int A = 26;

mint ways[N][N];
int nxt[N][A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  fill(nxt[n], nxt[n] + A, n);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < A; ++j) {
      nxt[i][j] = s[i] - 'a' == j ? i : nxt[i + 1][j];
    }
  }

  ways[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < A; ++k) {
        if (nxt[j][k] < n) {
          ways[i + 1][nxt[j][k]] += ways[i][j];
        }
      }
    }
  }

  cout << accumulate(ways[n], ways[n] + n, (mint) 0) << "\n";
}