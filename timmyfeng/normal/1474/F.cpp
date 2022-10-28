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

const int N = 50 + 1;

long long peak[N];

mint evaluate(vector<array<mint, 2>> &f, mint x) {
  int degree = (int) f.size();
  mint res = 0;

  for (int i = 0; i < degree; ++i) {
    mint num = 1, den = 1;
    for (int j = 0; j < degree; ++j) {
      if (i != j) {
        num *= x - f[j][0];
        den *= f[i][0] - f[j][0];
      }
    }
    res += f[i][1] * num * den.pow();
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  for (int i = 1; i <= n; ++i) {
    int d;
    cin >> d;
    peak[i] = peak[i - 1] + d;
  }

  long long length = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      length = max(length, peak[j] - peak[i] + 1);
    }
  }

  if (length == 1) {
    cout << 1 << " " << mint(-peak[n] + 1) << "\n";
    exit(0);
  }

  mint ans = 0;
  for (int l = 0; l <= n; ++l) {
    int r = -1;
    for (int i = l; i <= n; ++i) {
      if (peak[i] - peak[l] + 1 == length) {
        r = i;
      }
    }

    if (r == -1) {
      continue;
    }

    map<long long, vector<array<mint, 2>>> ways;
    ways[peak[l] - 1] = {{0, 1}};
    ways[peak[l] + 1] = {};

    for (int i = l; i < r; ++i) {
      if (peak[i + 1] == peak[i]) {
        continue;
      }

      map<long long, vector<array<mint, 2>>> new_ways = ways;
      if (peak[i + 1] > peak[i]) {
        new_ways[peak[i] + 1] = (--ways.upper_bound(peak[i] + 1))->second;
        new_ways[peak[i + 1] + 1] = (--ways.upper_bound(peak[i + 1] + 1))->second;

        for (auto it = ++new_ways.begin(); it != new_ways.end(); ++it) {
          auto &[x, f] = *it;
          if (x > peak[i] && x <= peak[i + 1]) {
            auto prv = it, nxt = it;
            --prv, ++nxt;

            vector<array<mint, 2>> g;
            mint prefix = evaluate(prv->second, x - 1);
            for (long long y = x; y < min(x + N, nxt->first); ++y) {
              prefix += evaluate(f, y);
              g.push_back({y, prefix});
            }
            f = g;
          }
        }
      } else {
        new_ways[peak[i]] = (--ways.upper_bound(peak[i]))->second;
        new_ways[peak[i + 1]] = (--ways.upper_bound(peak[i + 1]))->second;

        for (auto &[x, f] : ways) {
          if (x >= peak[i + 1] && x < peak[i]) {
            if (new_ways.count(x + 1) == 0) {
              new_ways[x + 1] = f;
            }
          }
        }

        for (auto it = ++new_ways.begin(); it != new_ways.end(); ++it) {
          auto &[x, f] = *it;
          if (x >= peak[i + 1] && x < peak[i]) {
            auto prv = it, nxt = it;
            --prv, ++nxt;

            vector<array<mint, 2>> g;
            mint value = evaluate((--ways.lower_bound(x))->second, x - 1);
            for (long long y = x; y < min(x + N, nxt->first); ++y) {
              mint new_value = evaluate(f, y);
              g.push_back({y, value + new_value});
              value = new_value;
            }
            f = g;
          }
        }
      }
      swap(ways, new_ways);
    }

    ans += evaluate((--ways.upper_bound(peak[r]))->second, peak[r]);

    l = r;
  }

  cout << length << " " << ans << "\n";
}