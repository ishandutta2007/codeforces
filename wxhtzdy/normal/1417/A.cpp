/**
 *  author: milos
 *  created: 01.10.2020 07:20:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    bool flag = false;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > k) {
        flag = true;  
      }
    }
    if (flag) {
      cout << 0 << '\n';
      continue;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 1; i < n; i++) {
      ans += (k - a[i]) / a[0];
    }           
    cout << ans << '\n';
  }
  return 0;
}