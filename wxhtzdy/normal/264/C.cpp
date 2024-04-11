#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    --c[i];
  }
  vector<long long> dp(n);
  while (q--) {
    int a, b;
    cin >> a >> b;
    const long long inf = 1e18;
    fill(dp.begin(), dp.end(), -inf);
    long long m1 = 0, m2 = 0;
    for (int i = 0; i < n; i++) {
      long long foo = max((dp[c[i]] == m1 ? m2 : m1) + (long long) v[i] * b, dp[c[i]] + (long long) v[i] * a);
      if (dp[c[i]] > foo) continue;
      if (m1 == dp[c[i]]) m1 = foo;
      else {
        long long x = foo;
        if (x > m1) swap(m1, x);
        if (x > m2) swap(m2, x);
      }
      dp[c[i]] = foo;
    }
    cout << max(0LL, *max_element(dp.begin(), dp.end())) << '\n';
  }
  return 0;
}