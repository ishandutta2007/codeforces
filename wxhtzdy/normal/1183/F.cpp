/**
 *    author:  milos
 *    created: 28.01.2021 10:29:07       
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
    set<int> s;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);  
    }
    int ans = 0, mx = *prev(s.end());
    if (mx % 2 == 0 && mx % 3 == 0 && mx % 5 == 0) {
      if (s.find(mx / 2) != s.end() && s.find(mx / 3) != s.end() && s.find(mx / 5) != s.end()) {
        ans = mx / 2 + mx / 3 + mx / 5;
      }
    }                     
    vector<int> b;
    while ((int) s.size() > 0 && (int) b.size() < 3) {
      auto it = prev(s.end());
      mx = *it, s.erase(it);
      bool ok = true;
      for (int i = 0; i < (int) b.size(); i++) {
        if (b[i] % mx == 0) {
          ok = false;
        }
      }
      if (ok) {
        b.push_back(mx);
      }
    }                      
    int sum = 0;
    for (int i = 0; i < (int) b.size(); i++) {
      sum += b[i];
    }
    ans = max(ans, sum);
    cout << ans << '\n';
  }
  return 0;
}