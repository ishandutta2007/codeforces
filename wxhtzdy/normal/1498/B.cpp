/**
 *    author:  milos
 *    created: 29.03.2021 16:38:40       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    multiset<int> s;
    for (int i = 0; i < n; i++) {
      int need = w - a[i];
      auto it = s.lower_bound(need + 1);
      if (it == s.begin() || s.empty()) {
        s.insert(a[i]);
      } else {
        it = prev(it);
        int val = *it;
        s.erase(it);
        s.insert(a[i] + val);
      }  
    }
    cout << (int) s.size() << '\n';
  }
  return 0;
}