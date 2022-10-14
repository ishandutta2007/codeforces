/**
 *    author:  wxhtzdy
 *    created: 06.08.2022 16:45:25
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
    int p = 1;
    while (p * p < n - 1) {
      p += 1;
    }
    vector<int> ans(n);
    set<int> used;                
    for (int i = n - 1; i >= 0; i--) {
      while (p * p - i < 0 || p * p - i >= n || used.count(p * p - i)) {
        p -= 1;
      }
      ans[i] = p * p - i;
      used.insert(ans[i]);
    }
    if (used.size() != n) {
      cout << -1 << '\n';
    } else {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
      }
    }
  }                                                                    
  return 0;
}