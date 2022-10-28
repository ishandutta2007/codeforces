#include <bits/stdc++.h>
using namespace std;

using matrix = vector<vector<long long>>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, l, n, q;
  cin >> x >> l >> n >> q;

  int log_n = 0;
  while ((1 << log_n) <= n) {
    ++log_n;
  }

  vector<int> c(l + 1);
  for (int i = 1; i <= l; ++i) {
    cin >> c[i];
  }

  map<int, int> stones;
  vector<int> stops = {n - x};
  for (int i = 0; i < q; ++i) {
    int p, w;
    cin >> p >> w;
    stones[p] = w;
    for (int j = 1; j <= l; ++j) {
      stops.push_back(p - j);
    }
  }

  sort(stops.begin(), stops.end());
  while (stops.back() > n - x) {
    stops.pop_back();
  }

  vector<matrix> pow_matrix(log_n);
  pow_matrix[0].assign(1 << l, vector<long long>(1 << l, LLONG_MAX / 2));

  for (int i = 0; i < (1 << l); ++i) {
    if ((i & 1) == 0) {
      pow_matrix[0][i][i >> 1] = 0;
    } else {
      for (int j = 1; j <= l; ++j) {
        if ((i & (1 << j)) == 0) {
          pow_matrix[0][i][(i ^ (1 << j)) >> 1] = c[j];
        }
      }
    }
  }

  auto mul = [](const matrix& a, const matrix& b) -> matrix {
    int n = a.size();
    matrix c(n, vector<long long>(n, LLONG_MAX / 2));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          c[i][k] = min(c[i][k], a[i][j] + b[j][k]);
        }
      }
    }
    return c;
  };

  for (int i = 1; i < log_n; ++i) {
    pow_matrix[i] = mul(pow_matrix[i - 1], pow_matrix[i - 1]);
  }

  auto mul_vector = [](const matrix& a, const vector<long long>& b) -> vector<long long> {
    int n = a.size();
    vector<long long> c(n, LLONG_MAX / 2);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        c[j] = min(c[j], a[i][j] + b[i]);
      }
    }
    return c;
  };

  vector<long long> dp(1 << l, LLONG_MAX / 2);
  dp[(1 << x) - 1] = 0;
  int pos = 1;

  for (auto i : stops) {
    if (i < pos) {
      continue;
    }

    for (int j = log_n - 1; j >= 0; --j) {
      if (pos + (1 << j) <= i) {
        dp = mul_vector(pow_matrix[j], dp);
        pos += 1 << j;
      }
    }

    vector<long long> dp_new(1 << l, LLONG_MAX / 2);
    for (int j = 0; j < (1 << l); ++j) {
      if ((j & 1) == 0) {
        dp_new[j >> 1] = min(dp_new[j >> 1], dp[j]);
      } else {
        for (int k = 1; k <= l; ++k) {
          if ((j & (1 << k)) == 0) {
            long long cost = dp[j] + c[k];
            if (stones.count(pos + k)) {
              cost += stones[pos + k];
            }
            int mask = (j ^ (1 << k)) >> 1;
            dp_new[mask] = min(dp_new[mask], cost);
          }
        }
      }
    }

    dp = dp_new;
    ++pos;
  }

  cout << dp[(1 << x) - 1] << "\n";
}