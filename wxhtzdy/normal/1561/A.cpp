/**
 *    author:  milos
 *    created: 25.08.2021 05:24:51       
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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    while (!is_sorted(a.begin(), a.end())) {
      for (int i = ans % 2; i < n - 1; i += 2) {
        if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);  
      }
      ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}