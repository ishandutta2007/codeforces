/**
 *    author:  milos
 *    created: 10.03.2021 13:12:36       
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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (k == 0) {
      cout << n << '\n';
      continue;
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
      s.insert(a[i]);
    }
    sort(a.begin(), a.end());
    int ans = (int) s.size();
    if (a[0] > 0) {
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (a[i] == (a[n - 1] + 1) / 2) {
          ok = false;
        }
      }
      ans += ok;
      cout << ans << '\n';
      continue;
    }                        
    bool ok = true;
    ans = n;
    for (int i = 1; i < n - 1; i++) {
      /*if (a[i] < a[i + 1] - 1) {
        s.insert();
        break;
      }
      dif = min(a[i + 1] - a[i], k);
      ans += dif;
      k -= dif; */   
      if (a[i] > a[i - 1] + 1) {
        if (s.find((a[i - 1] + 1 + a[n - 1] + 1) / 2) != s.end()) {
          ok = false;   
        } else {
          ok = false;
          ans++;
          break;
        }
      }
    }
    if (!ok) {
      cout << ans << '\n';
    } else {
      cout << n + k << '\n';
    }
    //cout << ans + k << '\n';
  }
  return 0;
}