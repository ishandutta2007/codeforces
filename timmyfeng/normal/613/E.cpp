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

const int N = 2000 + 1;

string puzzle[2], key;
int lcp[N][N][2][2];
mint ways[N][N][2];
int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (auto &i : puzzle) {
    cin >> i;
  }
  cin >> key;
  n = puzzle[0].size(), m = key.size();

  mint ans = 0;
  for (int z = 0; z < 2; ++z) {
    for (int i = m - 1; i >= 0; --i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < 2; ++k) {
          if (key[i] == puzzle[k][j]) {
            lcp[i][j][k][0] = (j < n - 1) ? lcp[i + 1][j + 1][k][0] + 1 : 1;
            lcp[i][j][k][1] = (j > 0) ? lcp[i + 1][j - 1][k][1] + 1 : 1;
          } else {
            lcp[i][j][k][0] = lcp[i][j][k][1] = 0;
          }
        }
      }
    }

    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k < 2; ++k) {
          if (i == 0) {
            ways[i][j][k] = 1;
          } else if (i % 2 == 0 && i / 2 <= j) {
            if (min(lcp[0][j - 1][1 - k][1], lcp[i / 2][j - i / 2][k][0]) >= i / 2) {
              ways[i][j][k] = (i < m);
            } else {
              ways[i][j][k] = 0;
            }
          } else {
            ways[i][j][k] = 0;
          }
        }
      }
    }

    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k < 2; ++k) {
          if (i == m) {
            ans += ways[i][j][k];
          } else if ((m - i) % 2 == 0 && j + (m - i) / 2 <= n) {
            if (min(lcp[i][j][k][0], lcp[i + (m - i) / 2][j + (m - i) / 2 - 1][1 - k][1]) >= (m - i) / 2) {
              ans += ways[i][j][k];
            }
          }

          if (i > 0 && i < m - 2 && j < n) {
            if (key[i] == puzzle[k][j] && key[i + 1] == puzzle[1 - k][j]) {
              ways[i + 2][j + 1][1 - k] += ways[i][j][k];
            }
          }

          if (i < m && j < n) {
            if (key[i] == puzzle[k][j]) {
              ways[i + 1][j + 1][k] += ways[i][j][k];
            }
          }
        }
      }
    }

    for (int i = 0; i < 2; ++i) {
      reverse(puzzle[i].begin(), puzzle[i].end());
    }
  }

  if (m == 1) {
    ans *= mint(2).pow();
  } else if (m == 2) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        ans -= (key[0] == puzzle[j][i] && key[1] == puzzle[1 - j][i]);
      }
    }
  }

  cout << ans << "\n";
}