#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;
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

const int N = 5000;

mint fact_inv[N];
mint fact[N];

mint ways[N];
int fish[N];
int a[N];

void init_fact() {
  fact[0] = 1;
  fact_inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i;
    fact_inv[i] = pow(fact[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  init_fact();

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);

  if (a[n - 2] * 2 > a[n - 1]) {
    cout << 0 << "\n";
    exit(0);
  }

  int half = 0;
  for (int i = 0; i < n; ++i) {
    while (half < i && a[half] * 2 <= a[i]) {
      ++half;
    }
    fish[i] = half + 1;

    for (int j = 0; j < half; ++j) {
      ways[i] += ways[j] * fact[n - fish[j] - 1] * fact_inv[n - 1 - half];
    }
    ways[i] += fact[n - 1] * fact_inv[n - 1 - half];
  }

  cout << ways[n - 1] << "\n";
}