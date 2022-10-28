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

const int A = 10000000 + 1;
const int N = 500000 + 1;
const int L = 8;

int sieve[A], mu[A], freq[A], multiples[A];
int prime[L], factor[1 << L];
mint pow2[N], res[A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  pow2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pow2[i] = 2 * pow2[i - 1];
  }

  for (int i = 2; i < A; ++i) {
    if (sieve[i] == 0) {
      for (int j = i; j < A; j += i) {
        sieve[j] = i;
      }
    }
  }

  for (int i = 1; i < A; ++i) {
    mu[i] = 1;
    int x = i;
    while (x > 1) {
      int p = sieve[x], a = 0;
      while (x % p == 0) {
        x /= p;
        ++a;
      }

      if (a == 1) {
        mu[i] *= -1;
      } else {
        mu[i] = 0;
      }
    }
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++freq[a];
  }

  for (int i = 1; i < A; ++i) {
    for (int j = i; j < A; j += i) {
      multiples[i] += freq[j];
    }
  }

  mint ans = 0;
  for (int i = 2; i < A; ++i) {
    if (multiples[i] == 0) {
      continue;
    }

    mint sets = 0;
    for (int j = 1; i * j < A; ++j) {
      sets += mu[j] * (pow2[multiples[i * j]] - 1);
    }

    int x = i, a = 0;
    while (x > 1) {
      int p = sieve[x];
      while (x % p == 0) {
        x /= p;
      }
      prime[a++] = p;
    }

    int coprime = 0;
    for (int j = 0; j < (1 << a); ++j) {
      if (j > 0) {
        factor[j] = factor[j - (j & -j)] * prime[__builtin_ctz(j)];
      } else {
        factor[j] = 1;
      }

      if (__builtin_parity(j) == 0) {
        coprime += multiples[factor[j]];
      } else {
        coprime -= multiples[factor[j]];
      }
    }

    ans += sets * coprime;
  }

  cout << ans << "\n";
}