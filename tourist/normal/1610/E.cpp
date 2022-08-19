/**
 *    author:  tourist
 *    created: 23.11.2021 17:59:20       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int eq = n - 1;
    int ans = 1;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] != a[i + 1]) {
        eq = i;
      }
      int j = max(i + 1, eq);
      int cnt = j - i + 1;
      while (j < n) {
        long long val = a[j] + (a[j] - a[i]);
        auto it = lower_bound(a.begin() + j + 1, a.end(), val);
        if (it == a.end()) {
          break;
        }
        j = (int) (it - a.begin());
        cnt += 1;
      }
      ans = max(ans, cnt);
    }
    cout << n - ans << '\n';
  }
  return 0;
}