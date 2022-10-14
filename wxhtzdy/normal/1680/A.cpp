#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int ans = 1e9;
    for (int i = 1; i <= 50; i++) {
      if (l1 <= i && i <= r1 && l2 <= i && i <= r2) {
        ans = min(ans, i);
      }
    }
    ans = min(ans, l1 + l2);
    cout << ans << '\n';
  }                                                                    
  return 0;
}