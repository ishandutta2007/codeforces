/**
 *    author:  milos
 *    created: 17.03.2021 15:40:43       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), cnt(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i] % m]++;
    }
    int ans = (cnt[0] > 0 ? 1 : 0);
    for (int i = 1; i < m; i++) {
      if (i + i == m || i + i == 0) {
        if (cnt[i] > 0) {
          ans++;
        }
        //cout << i << " " << ans << '\n';
      } else {
        if (cnt[i] > 0) {
          ans++;
        } else {
          continue;
        }
        if (abs(cnt[i] - cnt[(m - i) % m]) > 1) {
          //ans++;
        }
        ans += max(0, abs(cnt[i] - cnt[(m - i) % m]) - 1);
        cnt[i] = 0;
        cnt[(m - i) % m] = 0;
        //cout << i << " " << ans << '\n';
      }
    }
    cout << ans << '\n';
  }
  return 0;
}