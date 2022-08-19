/**
 *    author:  tourist
 *    created: 28.10.2018 18:52:35       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    y[i] -= x[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int foo, bar;
    cin >> foo >> bar;
    foo--; bar--;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  long long sum_x = accumulate(x.begin(), x.end(), 0LL);
  vector<long long> sorted_y = y;
  sort(sorted_y.begin(), sorted_y.end());
  vector<long long> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + sorted_y[i];
  }
  for (int i = 0; i < n; i++) {
    long long ans = x[i] * (n - 1) + (sum_x - x[i]);
    int pos = (int) (lower_bound(sorted_y.begin(), sorted_y.end(), y[i]) - sorted_y.begin());
    ans += pref[pos] + y[i] * (n - pos - 1);
    for (int j : g[i]) {
      long long cur = x[i] + x[j] + min(y[i], y[j]);
      ans -= cur;
    }
    if (i > 0) {
      cout << " ";
    }
    cout << ans;
  }
  cout << '\n';
  return 0;
}