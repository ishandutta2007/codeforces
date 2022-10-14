/**
 *    author:  milos
 *    created: 29.04.2021 19:38:40       
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
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<vector<int>> c(n);
    for (int i = 0; i < n; i++) {
      c[a[i] - 1].push_back(b[i]);
    }
    vector<long long> ans(n);
    for (int i = 0; i < n; i++) {
      if (c[i].empty()) {
        continue;
      }
      sort(c[i].rbegin(), c[i].rend());
      int m = (int) c[i].size();
      vector<long long> s(m);
      s[0] = c[i][0];
      for (int j = 1; j < m; j++) {
        s[j] = s[j - 1] + c[i][j];
      }
      for (int j = 1; j <= m; j++) {
        if (m == m % j) {
          continue;
        }
        ans[j - 1] += s[m - m % j - 1];
      }
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}