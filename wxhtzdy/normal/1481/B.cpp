/**
 *    author:  milos
 *    created: 05.02.2021 15:41:28       
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
    int sum = *max_element(a.begin(), a.end()) * n;
    if (sum < k) {
      cout << -1 << '\n';
      continue;
    }
    int ans = -1;
    while (k > 0) {
      bool ok = false;
      for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
          ok = true;
          a[i]++;
          if (k == 1) {
            ans = i + 1;
          }
          break;
        }
      }
      if (!ok) {
        break;
      }
      k--;
    }
    cout << ans << '\n';
  }
  return 0;
}