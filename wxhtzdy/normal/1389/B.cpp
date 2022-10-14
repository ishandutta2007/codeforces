/**
 *    author:  milos
 *    created: 13.04.2021 23:08:55       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0, sum = 0;
    for (int i = 0; i <= k; i++) {
      sum += a[i];
    }
    ans = sum;
    for (int i = 1; i <= k; i++) {
      long long nans = sum;
      int need = k - i;
      for (int j = 0; j < min(z * 2, need); j++) {
        nans -= a[k - j];
        if (j % 2 == 0) {
          nans += a[i - 1];
        } else {
          nans += a[i];
        }
      }
      ans = max(ans, nans);  
    }
    cout << ans << '\n';
  }
  return 0;
}