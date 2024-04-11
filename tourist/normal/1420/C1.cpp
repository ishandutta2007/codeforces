/**
 *    author:  tourist
 *    created: 24.09.2020 20:27:54       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    assert(q == 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    // maximize a[b[1]] - a[b[2]] + a[b[3]] - a[b[4]] + ...
    // maximize a[b[1]] - (a[b[2]] - a[b[3]] + a[b[4]] - a[b[5]] + ...)
    vector<long long> mx(n + 1);
    vector<long long> mn(n + 1);
    // mx[i] and mn[i] == max and min strength of a team chosen from a[i], a[i + 1], ..., a[n - 1]
    for (int i = n - 1; i >= 0; i--) {
      // mx[i + 1], mn[i + 1]
      mx[i] = max(mx[i + 1], a[i] - mn[i + 1]);
      mn[i] = min(mn[i + 1], a[i] - mx[i + 1]);
      // assume a[i] < mx[i + 1] + mn[i + 1]:
      // a[i] - mn[i + 1] < mx[i + 1]   =>    mx[i] = mx[i + 1]             -- doesn't change
      // a[i] - mx[i + 1] < mn[i + 1]   =>    mn[i] = a[i] - mx[i + 1]

      // assume a[i] >= mx[i + 1] + mn[i + 1]:
      // a[i] - mn[i + 1] >= mx[i + 1]  =>    mx[i] = a[i] - mn[i + 1]      -- increases by (a[i] - a[i + 1])
      // a[i] - mx[i + 1] >= mn[i + 1]  =>    mn[i] = mn[i + 1]

      // in both cases: mx[i] + mn[i] == a[i]

//      cerr << a[i] << " " << mx[i] << " " << mn[i] << '\n';
    }
    cout << mx[0] << '\n';
  }
  return 0;
}