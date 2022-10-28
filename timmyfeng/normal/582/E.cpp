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

const int N = 16;

int x[N], y[N];

void subset(vector<mint> &a, int k) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < (1 << N); ++j) {
      if ((j & (1 << i)) > 0) {
        a[j] += a[j ^ (1 << i)] * k;
      }
    }
  }
}

void invert(vector<mint> &a) {
  for (int j = 0; j < (1 << N); j += 2) {
    swap(a[j], a[((1 << N) - 1) ^ j]);
  }
}

vector<mint> solve(string s) {
  if (s.size() == 1) {
    vector<mint> res(1 << N);
    for (int i = 0; i < 4; ++i) {
      if (s[0] == 'A' + i || s[0] == '?') {
        int mask = 0;
        for (int j = 0; j < N; ++j) {
          if ((j & (1 << i)) > 0) {
            mask ^= 1 << j;
          }
        }
        ++res[mask];
      }
    }

    for (int i = 0; i < 4; ++i) {
      if (s[0] == 'a' + i || s[0] == '?') {
        int mask = 0;
        for (int j = 0; j < N; ++j) {
          if ((j & (1 << i)) == 0) {
            mask ^= 1 << j;
          }
        }
        ++res[mask];
      }
    }

    return res;
  } else {
    int balance = 0, index = 0;
    for ( ; index < (int) s.size(); ++index) {
      if (s[index] == '(') {
        ++balance;
      } else if (s[index] == ')') {
        --balance;
      } else if (balance == 0) {
        break;
      }
    }

    vector<mint> left = solve(s.substr(1, index - 2));
    vector<mint> right = solve(s.substr(index + 2, s.size() - index - 3));

    vector<mint> ways(1 << N);

    if (s[index] == '&' || s[index] == '?') {
      invert(left), invert(right);
      subset(left, 1), subset(right, 1);
      for (int i = 0; i < (1 << N); ++i) {
        ways[i] += left[i] * right[i];
      }
      subset(ways, -1), subset(left, -1), subset(right, -1);
      invert(ways), invert(left), invert(right);
    }

    if (s[index] == '|' || s[index] == '?') {
      subset(left, 1), subset(right, 1), subset(ways, 1);
      for (int i = 0; i < (1 << N); ++i) {
        ways[i] += left[i] * right[i];
      }
      subset(ways, -1);
    }

    return ways;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> s >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      int a;
      cin >> a;
      x[i] ^= a << j;
    }
    cin >> y[i];
  }

  vector<mint> ways = solve(s);
  mint ans = 0;

  for (int i = 0; i < (1 << N); ++i) {
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      ok &= (((i & (1 << x[j])) > 0) == y[j]);
    }

    if (ok) {
      ans += ways[i];
    }
  }

  cout << ans << "\n";
}