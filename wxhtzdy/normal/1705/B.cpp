/**
 *    author:  wxhtzdy
 *    created: 18.07.2022 20:25:19
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
    bool was = false;
    long long ans = 0;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] > 0) {
        was = true;
      }
      ans += a[i];
      if (a[i] == 0) {
        ans += was;
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}