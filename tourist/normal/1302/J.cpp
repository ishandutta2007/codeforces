/**
 *    author:  tourist
 *    created: 17.02.2020 18:34:19       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < a[i]; j++) {
        if (d >= i) {
          d -= i;
          ++ans;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}