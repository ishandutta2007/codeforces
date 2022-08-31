/**
 *    author:  tourist
 *    created: 14.09.2020 21:49:28       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // x1 * y1 = x2 * y2
  // x1 / x2 = y2 / y1
  // let g = gcd(x1, x2)
  // (x1 / g) / (x2 / g) = y2 / y1
  // let k = x1 / g
  // we can have fractions of form: k / (k + t), for some t
  // k / (k + t) = y2 / y1
  //   <=>    y2 = k * p
  //          y1 = (k + t) * p

  // (k + t) * g <= n
  // (k + t) * p <= m
  // ceil(l / x1) <= (k + t) * p <= floor(r / x1)

  // 1 <= t <= n / g - k
  // ceil(l / x1) <= (k + t) * p <= min(m, floor(r / x1))

  long long n, m, l, r;
  cin >> n >> m >> l >> r;
  vector<array<long long, 4>> res(n + 1, {-1, -1, -1, -1});
  for (long long g = 1; g <= n; g++) {
    for (long long x1 = g; x1 <= n; x1 += g) {
      long long k = x1 / g;
      long long min_t = 1;
      long long max_t = n / g - k;
      long long min_v = (l + x1 - 1) / x1;
      long long max_v = min(m, r / x1);
      if (min_t <= max_t && min_v <= max_v) {
        // t <= p?
        for (long long t = min_t; t <= max_t && (k + t) * t <= max_v && res[x1][0] == -1; t++) {
          // min_v <= (k + t) * p <= max_v
          long long min_p = (min_v + (k + t - 1)) / (k + t);
          long long max_p = max_v / (k + t);
          if (min_p <= max_p) {
            long long p = min_p;
            res[x1][0] = x1;
            res[x1][1] = (k + t) * p;
            res[x1][2] = x1 + t * g;
            res[x1][3] = k * p;
          }
        }
        // t >= p?
        for (long long p = 1; (k + p) * p <= max_v && res[x1][0] == -1; p++) {
          // ceil(min_v / p) <= k + t <= floor(max_v / p)
          long long new_min_t = max(min_t, (min_v + p - 1) / p - k);
          long long new_max_t = min(max_t, max_v / p - k);
          if (new_min_t <= new_max_t) {
            long long t = new_min_t;
            res[x1][0] = x1;
            res[x1][1] = (k + t) * p;
            res[x1][2] = x1 + t * g;
            res[x1][3] = k * p;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (res[i][0] == -1) {
      cout << -1 << '\n';
    } else {
      cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << " " << res[i][3] << '\n';
    }
  }
  return 0;
}