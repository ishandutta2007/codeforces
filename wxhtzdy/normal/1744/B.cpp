/**
 *    author:  wxhtzdy
 *    created: 16.10.2022 16:37:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    long long s = 0;
    vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;        
      cnt[x & 1] += 1;
      s += x;
    }
    while (q--) {
      int op;
      cin >> op;
      int x;
      cin >> x;
      if (op == 0) {
        s += cnt[0] * 1LL * x;
        if (x & 1) {
          cnt[1] += cnt[0];
          cnt[0] = 0;
        }
      } else {
        s += cnt[1] * 1LL * x;
        if (x & 1) {
          cnt[0] += cnt[1];
          cnt[1] = 0;
        }
      }
      cout << s << '\n';
    }                     
  }                                                                  
  return 0;
}