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

const int N = 1000000 + 1;

map<int, mint> ways[N];
int a[N], v[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  long long l;
  cin >> n >> l >> k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    v[i] = a[i];
    ways[0][v[i]] = 1;
  }
  sort(v, v + n);

  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (ways[i].count(v[j]) == 0) {
        ways[i][v[j]] = (j == 0) ? 0 : ways[i][v[j - 1]];
      }
      ways[i][v[j]] += ways[i - 1][v[j]];
    }
  }

  mint ans = 0;
  for (int i = 1; i <= k; ++i) {
    ans += max(0LL, l / n + 1 - i) * ways[i][v[n - 1]];
    if (i - 1 <= l / n) {
      for (int j = 0; j < l % n; ++j) {
        ans += ways[i - 1][a[j]];
      }
    }
  }

  cout << ans << "\n";
}