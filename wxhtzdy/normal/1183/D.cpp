/**
 *    author:  milos
 *    created: 28.01.2021 10:39:24       
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
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    sort(cnt.begin(), cnt.end());
    int sz = cnt[n];
    long long ans = cnt[n];
    for (int i = n - 1; i >= 0; i--) {
      if (sz == 0) {
        break;
      }
      if (cnt[i] >= sz) {
        ans += sz - 1;
        sz--;
      } else {
        ans += cnt[i];
        sz = cnt[i];
      }               
    }
    cout << ans << '\n';  
  }
  return 0;
}