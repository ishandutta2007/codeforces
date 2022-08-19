/**
 *    author:  tourist
 *    created: 04.06.2020 18:33:28       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  vector<int> y(n);
  vector<double> d(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    d[i] = sqrt((double) ((long long) x[i] * x[i] + (long long) y[i] * y[i]));
    if (x[i] != 0 || y[i] != 0) {
      int g = __gcd(abs(x[i]), abs(y[i]));
      x[i] /= g;
      y[i] /= g;
    }
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    if (x[i] != x[j]) {
      return x[i] < x[j];
    }
    if (y[i] != y[j]) {
      return y[i] < y[j];
    }
    return d[i] < d[j];
  });
  vector<double> r;
  int beg = 0;
  while (beg < n) {
    int end = beg;
    int dx = x[order[beg]];
    int dy = y[order[beg]];
    while (end + 1 < n && x[order[end + 1]] == dx && y[order[end + 1]] == dy) {
      end += 1;
    }
    int L = beg, R = end;
    for (int i = 0; i < k / 2 && L <= R; i++) {
      int coeff = k - 1 - 2 * i;
      r.push_back(d[order[R]] * coeff);
      R -= 1;
    }
    if (k % 2 == 0) {
      double sum = 0;
      while (L <= R) {
        r.push_back(-(sum + d[order[L]]));
        sum += 2 * d[order[L]];
        L += 1;
      }
    } else {
      double sum = 0;
      while (L <= R) {
        r.push_back(-sum);
        sum += 2 * d[order[L]];
        L += 1;
      }
    }
    beg = end + 1;
  }
  sort(r.rbegin(), r.rend());
  double ans = 0;
  for (int i = 0; i < k; i++) {
    ans += r[i];
  }
  cout << fixed << setprecision(17) << ans << '\n';
  return 0;
}