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

const mint G = 3;

void ntt(vector<mint> &a) {
  int n = a.size();

  vector<int> reverse(n);
  for (int i = 1; i < n; ++i) {
    reverse[i] = (reverse[i >> 1] >> 1) | ((i & 1) << (__lg(n) - 1));
  }

  for (int i = 0; i < n; ++i) {
    if (i < reverse[i]) {
      swap(a[i], a[reverse[i]]);
    }
  }
 
  for (int len = 1; len < n; len *= 2) {
    mint root = G.pow((M - 1) / len / 2);
    for (int i = 0; i < n; i += 2 * len) {
      mint cur = 1;
      for (int j = 0; j < len; ++j) {
        mint l = a[i + j], r = a[i + j + len] * cur;
        a[i + j] = l + r;
        a[i + j + len] = l - r;
        cur *= root;
      }
    }
  }
}
 
vector<mint> mul(vector<mint> a, vector<mint> b) {
  int n = 1, m = a.size() + b.size();
  while (n < m) {
    n *= 2;
  }
 
  a.resize(n), b.resize(n);
  ntt(a), ntt(b);
 
  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  ntt(a);
 
  mint inv = mint(n).pow();
  for (mint &i : a) {
    i *= inv;
  }
  reverse(a.begin() + 1, a.end());

  a.resize(m - 1);
  return a;
}

const int N = 200000 + 1;

mint fact[N], inv[N];

mint choose(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  } else {
    return fact[n] * inv[k] * inv[n - k];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  inv[0] = fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i;
    inv[i] = fact[i].pow();
  }

  int n;
  cin >> n;

  vector<mint> ways = {1};
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;

    vector<mint> coeffs(2 * ways.size() + a - b - 1);
    for (int j = 0; j < (int) coeffs.size(); ++j) {
      coeffs[j] = choose(a + b, b - ways.size() + 1 + j);
    }

    vector<mint> poly = mul(ways, coeffs);
    ways = vector<mint>(poly.begin() + ways.size() - 1, poly.end() - ways.size() + 1);
  }

  cout << accumulate(ways.begin(), ways.end(), mint()) << "\n";
}