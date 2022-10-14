/**       
 *    author:  milos
 *    created: 03.05.2021 09:38:05       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    vector<vector<int>> c(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    if (l > r) {
      swap(l, r);
      reverse(a.begin(), a.end());
    }
    for (int i = 0; i < n; i++) {
      if (i < l) {
        c[a[i]][0]++;
      } else {
        c[a[i]][1]++;
      }
    }
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      int x = c[i][0], y = c[i][1];
      cnt += min(x, y);
      ans += max((y - x) / 2, 0);
    }
    cnt += min(ans, (r - l) / 2);
    cout << n / 2 - cnt + (r - l) / 2 << '\n';
  }
  return 0;
}