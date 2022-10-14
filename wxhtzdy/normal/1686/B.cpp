/**
 *    author:  wxhtzdy
 *    created: 30.05.2022 23:05:00
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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
      if (p[i] > p[i + 1]) {
        ans += 1;
        i += 1;
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}