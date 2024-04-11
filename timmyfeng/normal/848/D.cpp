#include <bits/stdc++.h>
using namespace std;

template <int M>
struct modint {

  int val = 0;

  modint() {}

  modint(long long a) {
    val = a % M;
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

using mint = modint<int(1e9) + 7>;

const int N = 50 + 2;

mint dp_path[N][N];
mint dp[N][N];

mint mod_inv[N];

mint choose(mint n, int k) {
  mint res = 1;
  for (int i = 0; i < k; ++i) {
    res *= n - i;
    res *= mod_inv[i + 1];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  mod_inv[1] = 1;
  int M = 1e9 + 7;
  for (int i = 2; i < N; ++i) {
    mod_inv[i] = -mod_inv[M % i] * (M / i);
  }

  int n, m;
  cin >> n >> m;

  dp[0][1] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= n + 1; ++j) {
      if (dp[i][j] != 0) {
        for (int ii = 0; ii <= i; ++ii) {
          for (int jj = 1; jj <= (ii == i ? j : n + 1); ++jj) {
            int i_new = i + ii + 1;
            int j_new = min(j, jj);
            if (i_new <= n && j_new <= n + 1) {
              dp_path[i_new][j_new] += (i == ii && j == jj ? 1 : 2) * dp[i][j] * dp[ii][jj];
            }
          }
        }
      }

      if (dp_path[i][j] != 0) {
        for (int ii = n; ii >= 0; --ii) {
          for (int jj = n + 1; jj >= 1; --jj) {
            if (dp[ii][jj] != 0) {
              int k = 1;
              while (true) {
                int i_new = ii + k * i;
                int j_new = jj + k * j;
                if (i_new > n || j_new > n + 1) {
                  break;
                }
                dp[i_new][j_new] += choose(k - 1 + dp_path[i][j], k) * dp[ii][jj];
                ++k;
              }
            }
          }
        }
      }
    }
  }

  cout << dp[n][m].val << "\n";
}