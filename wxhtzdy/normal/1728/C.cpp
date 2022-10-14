/**
 *    author:  wxhtzdy
 *    created: 08.09.2022 16:43:31
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
    multiset<int> a;
    multiset<int> b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.insert(x);
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b.insert(x);
    }    
    int ans = 0;
    auto f = [&](int x) {
      int num = 1;
      int len = 1;
      while (num < 1e9 && num * 10 <= x) {
        num *= 10;
        len += 1;
      }
      return len;
    };
    while (!a.empty() && !b.empty()) {
      if (*prev(a.end()) == *prev(b.end())) {
        a.erase(prev(a.end()));
        b.erase(prev(b.end()));
        continue;
      }
      if (*prev(a.end()) > *prev(b.end())) {
        int x = *prev(a.end());
        a.erase(prev(a.end()));
        a.insert(f(x));
        ans += 1;      
      } else {
        int x = *prev(b.end());
        b.erase(prev(b.end()));
        b.insert(f(x));
        ans += 1;      
      
      }   
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}