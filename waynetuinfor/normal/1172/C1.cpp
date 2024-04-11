#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), w(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> w[i];
  constexpr int kMod = 998244353;

  auto fpow = [&](int a, int n) {
    a = (a % kMod + kMod) % kMod;
    int res = 1;
    while (n > 0) {
      if (n & 1) res = 1LL * res * a % kMod;
      a = 1LL * a * a % kMod;
      n >>= 1;
    }
    return res;
  };

  array<int, 2> sum{};
  for (int i = 0; i < n; ++i) sum[a[i]] += w[i];
  int all = sum[0] + sum[1];

  vector<vector<vector<int>>> prob(2);

  for (int a = 0; a < 2; ++a) {
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    for (int ph = 0; ph < m; ++ph) {
      vector<vector<int>> nxt(m + 1, vector<int>(m + 1));
      for (int j = 0; j <= m; ++j) {
        for (int k = 0; k <= m; ++k) {
          if (dp[j][k] == 0) continue;
          if (a == 0) {
            {
              int p = fpow(all - (j + k) + (ph - (j + k)), kMod - 2);
              nxt[j][k + 1] += 1LL * p * dp[j][k] % kMod;
              nxt[j][k + 1] >= kMod ? nxt[j][k + 1] -= kMod : 0;
            }
            {
              int p = fpow(all - (j + k) + (ph - (j + k)), kMod - 2);
              nxt[j + 1][k] += 1LL * p * dp[j][k] % kMod;
              nxt[j + 1][k] >= kMod ? nxt[j + 1][k] -= kMod : 0;
            }
            {
              int p = 1LL * (sum[1] + (ph - j - k)) * fpow(all - (j + k) + (ph - (j + k)), kMod - 2) % kMod;
              nxt[j][k] += 1LL * p * dp[j][k] % kMod;
              nxt[j][k] >= kMod ? nxt[j][k] -= kMod : 0;
            }
          } else {
            {
              int p = fpow(all + (j + k) - (ph - (j + k)), kMod - 2);
              nxt[j][k + 1] += 1LL * p * dp[j][k] % kMod;
              nxt[j][k + 1] >= kMod ? nxt[j][k + 1] -= kMod : 0;
            }
            {
              int p = fpow(all + (j + k) - (ph - (j + k)), kMod - 2);
              nxt[j + 1][k] += 1LL * p * dp[j][k] % kMod;
              nxt[j + 1][k] >= kMod ? nxt[j + 1][k] -= kMod : 0;
            }
            {
              int p = 1LL * (sum[0] - (ph - j - k)) * fpow(all + (j + k) - (ph - (j + k)), kMod - 2) % kMod;
              nxt[j][k] += 1LL * p * dp[j][k] % kMod;
              nxt[j][k] >= kMod ? nxt[j][k] -= kMod : 0;
            }
          }
        }
      }
      dp = nxt;
    }
    prob[a] = dp;
  }

  vector<vector<int>> poly(2);

  auto PolyAdd = [&](const vector<int> &a, const vector<int> &b) {
    vector<int> res(max(a.size(), b.size()));
    copy(a.begin(), a.end(), res.begin());
    for (int i = 0; i < b.size(); ++i) {
      (res[i] += b[i]) >= kMod ? res[i] -= kMod : 0;
    }
    return res;
  };

  auto PolyAddCoef = [&](const vector<int> &a, const vector<int> &b, int c) {
    vector<int> res(max(a.size(), b.size()));
    copy(a.begin(), a.end(), res.begin());
    for (int i = 0; i < b.size(); ++i) {
      res[i] += 1LL * c * b[i] % kMod;
      res[i] >= kMod ? res[i] -= kMod : 0;
    }
    return res;
  };

  auto PolyMul = [&](const vector<int> &a, const vector<int> &b) {
    vector<int> res(a.size() + b.size() - 1);
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        res[i + j] += 1LL * a[i] * b[j] % kMod;
        res[i + j] >= kMod ? res[i + j] -= kMod : 0;
      }
    }
    return res;
  };

  for (int a = 0; a < 2; ++a) {
    poly[a].assign(1, 0);
    vector<int> mult(1, 1);
    for (int r = 0; r <= m; ++r) {
      vector<int> p(1, 0), oth(1, 1);
      for (int j = 0; j <= m; ++j) {
        p = PolyAddCoef(p, PolyMul(mult, oth), prob[a][j][r]);
        vector<int> z = {0, kMod - 1};
        if (a) z[0] = sum[1] + j;
        else z[0] = (sum[0] + kMod - j) % kMod;
        oth = PolyMul(oth, z);
      }
      vector<int> val = {0, 1};
      if (a) val[0] = r;
      else val[0] = kMod - r;
      poly[a] = PolyAdd(poly[a], PolyMul(p, val));
      mult = PolyMul(mult, val);
    }
  }

  auto Eval = [&](const vector<int> &p, int v) {
    int x = 1, res = 0;
    for (int i = 0; i < p.size(); ++i) {
      res += 1LL * x * p[i] % kMod;
      res >= kMod ? res -= kMod : 0;
      x = 1LL * x * v % kMod;
    }
    return res;
  };

  for (int i = 0; i < n; ++i) {
    /* int res = 0;
    int mult = 1;
    for (int r = 0; r <= m; ++r) {
      int p = 0;
      int oth = 1;
      for (int j = 0; j <= m; ++j) {
        // cout << "dp = " << dp[j][r] << endl;
        // cout << "oth = " << oth << " mult = " << mult << endl;
        (p += 1LL * mult * oth % kMod * prob[a[i]][j][r] % kMod) >= kMod ? p -= kMod : 0;
        oth = 1LL * oth * (a[i] == 0 ? sum[0] - w[i] - j : sum[1] - w[i] + j) % kMod;
      }
      // cout << "p = " << p << endl;
      int val = !a[i] ? w[i] - r : w[i] + r;
      res += 1LL * p * val % kMod;
      res >= kMod ? res -= kMod : 0;
      mult = 1LL * mult * val % kMod;
    } */
    cout << Eval(poly[a[i]], w[i]) << "\n";
  }
  return 0;
}