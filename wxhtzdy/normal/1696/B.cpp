/**
 *    author:  wxhtzdy
 *    created: 26.06.2022 18:27:49
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
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        continue;
      }
      if (i == 0 || a[i - 1] == 0) {
        ans += 1;
      }
    }
    ans = min(ans, 2);
    cout << ans << '\n';
  } 
  return 0;
}