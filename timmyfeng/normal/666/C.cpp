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

const int N = 100000 + 1;
const int A = 26;

vector<mint> ways[N];
mint fact[N], inv[N];

mint choose(int n, int k) {
  return fact[n] * inv[k] * inv[n - k];
}

void precalc(int s) {
  if (!ways[s].empty()) {
    return;
  }

  mint power = 1;
  ways[s].resize(N);
  for (int i = s; i < N; ++i) {
    ways[s][i] = ways[s][i - 1] * A + choose(i - 1, s - 1) * power;
    power *= A - 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  inv[0] = fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i;
    inv[i] = pow(fact[i]);
  }

  int m;
  string s;
  cin >> m >> s;

  precalc(s.size());

  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      cin >> s;
      precalc(s.size());
    } else {
      int n;
      cin >> n;
      cout << ways[s.size()][n] << "\n";
    }
  }
}