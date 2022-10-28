#include <bits/stdc++.h>
using namespace std;

template <int M>
struct modint {

  int val = 0;

  modint() {}

  modint(int a) : val(a) {
    while (val < 0) {
      val += M;
    }
    while (val >= M) {
      val -= M;
    }
  }

  modint(long long a) : val(a % M) {
    if (val < 0) {
      val += M;
    }
  }

  modint operator+=(modint oth) {
    val += oth.val;
    if (val >= M) {
      val -= M;
    }
    return *this;
  }

  modint operator-=(modint oth) {
    val -= oth.val;
    if (val < 0) {
      val += M;
    }
    return *this;
  }

  modint operator*=(modint oth) {
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

  modint operator-() {
    modint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }

  int mod() {
    return M;
  }

  modint pow(int e) {
    modint base = val;
    modint res = 1;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= base;
      }
      base *= base;
      e /= 2;
    }
    return res;
  }

  modint inv() {
    return pow(M - 2);
  }

  friend modint operator+(modint a, modint b) {
    return modint(a) += b;
  }

  friend modint operator-(modint a, modint b) {
    return modint(a) -= b;
  }

  friend modint operator*(modint a, modint b) {
    return modint(a) *= b;
  }

  friend bool operator==(modint a, modint b) {
    return a.val == b.val;
  }

  friend bool operator!=(modint a, modint b) {
    return a.val != b.val;
  }

};

using mint = modint<1'000'000'007>;
const int L = 31;

mint cnt[L + 1][2][2][2];
mint sum[L + 1][2][2][2];

mint solve(int x, int y, int k) {
  --x, --y, --k;
  if (x < 0 || y < 0) {
    return 0;
  }

  for (int i = 0; i <= L; ++i) {
    for (auto jx : {0, 1}) {
      for (auto jy : {0, 1}) {
        for (auto jk : {0, 1}) {
          cnt[i][jx][jy][jk] = 0;
          sum[i][jx][jy][jk] = 0;
        }
      }
    }
  }
  cnt[L][1][1][1] = 1;

  for (int i = L - 1; i >= 0; --i) {
    for (auto jx : {0, 1}) {
      for (auto jy : {0, 1}) {
        for (auto jk : {0, 1}) {
          for (auto kx : {0, 1}) {
            for (auto ky : {0, 1}) {
              int bx = jx;
              int by = jy;
              int bk = jk;

              if (jx == 1) {
                int c = ((x & (1 << i)) > 0);
                if (kx < c) {
                  bx = 0;
                } else if (kx > c) {
                  continue;
                }
              }

              if (jy == 1) {
                int c = ((y & (1 << i)) > 0);
                if (ky < c) {
                  by = 0;
                } else if (ky > c) {
                  continue;
                }
              }

              if (jk == 1) {
                int c = ((k & (1 << i)) > 0);
                if ((kx ^ ky) < c) {
                  bk = 0;
                } else if ((kx ^ ky) > c) {
                  continue;
                }
              }

              cnt[i][bx][by][bk] += cnt[i + 1][jx][jy][jk];
              sum[i][bx][by][bk] += sum[i + 1][jx][jy][jk] + cnt[i + 1][jx][jy][jk] * ((kx ^ ky) << i);
            }
          }
        }
      }
    }
  }

  mint res = 0;
  for (auto jx : {0, 1}) {
    for (auto jy : {0, 1}) {
      for (auto jk : {0, 1}) {
        res += cnt[0][jx][jy][jk] + sum[0][jx][jy][jk];
      }
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    --x1, --y1;
    cout << (solve(x2, y2, k) + solve(x1, y1, k) - solve(x2, y1, k) - solve(x1, y2, k)).val << "\n";
  }
}