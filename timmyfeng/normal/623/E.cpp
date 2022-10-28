#define _USE_MATH_DEFINES
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

using point = complex<double>;

const int N = 30000 + 1;

point roots[4 * N];

void fft(vector<point>& a) {
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
    for (int i = 0; i < n; i += 2 * len) {
      for (int j = 0; j < len; ++j) {
        point l = a[i + j], r = a[i + j + len] * roots[len + j];
        a[i + j] = l + r;
        a[i + j + len] = l - r;
      }
    }
  }
}

vector<point> mul(vector<point> a, vector<point> b) {
  int n = 1, m = a.size() + b.size();
  while (n < m) {
    n *= 2;
  }

  a.resize(n), b.resize(n);
  fft(a), fft(b);

  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  fft(a);

  for (auto &i : a) {
    i /= n;
  }
  reverse(a.begin() + 1, a.end());

  a.resize(m - 1);
  return a;
}

vector<mint> mul(vector<mint> &a, vector<mint> &b) {
  vector<point> p(a.size()), q(a.size());
  for (int i = 0; i < (int) a.size(); ++i) {
    p[i] = a[i].value & ((1 << 16) - 1);
    q[i] = a[i].value >> 16;
  }

  vector<point> r(b.size()), s(b.size());
  for (int i = 0; i < (int) b.size(); ++i) {
    r[i] = b[i].value & ((1 << 16) - 1);
    s[i] = b[i].value >> 16;
  }

  int n = a.size() + b.size() - 1;
  vector<mint> c(n);

  vector<point> d = mul(p, r);
  for (int i = 0; i < n; ++i) {
    c[i] += (long long) (d[i].real() + 0.5);
  }

  d = mul(p, s);
  for (int i = 0; i < n; ++i) {
    c[i] += (long long) (d[i].real() + 0.5) * mint(1LL << 16);
  }

  d = mul(q, r);
  for (int i = 0; i < n; ++i) {
    c[i] += (long long) (d[i].real() + 0.5) * mint(1LL << 16);
  }

  d = mul(q, s);
  for (int i = 0; i < n; ++i) {
    c[i] += (long long) (d[i].real() + 0.5) * mint(1LL << 32);
  }

  return c;
}

mint fact[N], inv[N];
int k;

mint choose(int n, int k) {
  return fact[n] * inv[k] * inv[n - k];
}

vector<mint> combine(vector<mint> a, vector<mint> b, int l) {
  for (int i = 0; i <= k; ++i) {
    a[i] *= mint(2).pow(i * l) * inv[i];
  }

  for (int i = 0; i <= k; ++i) {
    b[i] *= inv[i];
  }

  vector<mint> c = mul(a, b);
  c.resize(k + 1);

  for (int i = 0; i <= k; ++i) {
    c[i] *= fact[i];
  }

  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  fact[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i;
    inv[i] = fact[i].pow();
  }

  for (int i = 1; i <= 2 * N; i *= 2) {
    for (int j = 0; j < i; ++j) {
      roots[i + j] = polar(1.0, j * M_PI / i);
    }
  }

  long long n;
  cin >> n >> k;

  if (n > k) {
    cout << 0 << "\n";
    exit(0);
  }

  vector<mint> base(k + 1, 1), ways(k + 1);
  base[0] = 0, ways[0] = 1;
  long long e = 1;

  while (n > 0) {
    if (n % 2 == 1) {
      ways = combine(ways, base, e);
    }
    base = combine(base, base, e);
    e *= 2;
    n /= 2;
  }

  mint ans = 0;
  for (int i = n; i <= k; ++i) {
    ans += ways[i] * choose(k, i);
  }

  cout << ans << "\n";
}