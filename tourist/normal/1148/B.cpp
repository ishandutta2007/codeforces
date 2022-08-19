/**
 *    author:  tourist
 *    created: 01.06.2019 17:50:37       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  if (k >= min(n, m)) {
    cout << -1 << '\n';
    return 0;
  }
  int ans = 0;
  for (int x = 0; x <= k; x++) {
    int at_b = a[x] + ta;
    int pos = (int) (lower_bound(b.begin(), b.end(), at_b) - b.begin());
    pos += (k - x);
    if (pos >= m) {
      cout << -1 << '\n';
      return 0;
    }
    ans = max(ans, b[pos] + tb);
  }
  cout << ans << '\n';
  return 0;
}