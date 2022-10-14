/**
 *    author:  wxhtzdy
 *    created: 01.08.2022 16:38:38
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
    map<int, int> was;
    for (int i = n - 1; i >= 0; i--) {
      if (!was[a[i]]) {
        was[a[i]] += 1;
        ans += 1;
      } else {
        break;
      }
    }
    cout << n - ans << '\n';
  }                                                                    
  return 0;
}