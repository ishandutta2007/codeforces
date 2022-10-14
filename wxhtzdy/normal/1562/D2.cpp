/**
 *    author:  milos
 *    created: 03.09.2021 16:21:54       
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
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = (s[i] == '+' ? +1 : -1);
    }
    for (int i = 1; i < n; i += 2) {
      a[i] = -a[i];
    }
    vector<int> b(n + 1);
    for (int i = 0; i < n; i++) {
      b[i + 1] = b[i] + a[i];
    }      
    vector<vector<int>> pos(4 * n + 5);
    for (int i = 0; i < n; i++) {
      pos[b[i] + b[i + 1] + 2 * n].push_back(i);
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      if (b[r] == b[l - 1]) {
        cout << 0 << '\n';
        continue;
      }
      if (r % 2 == l % 2) {
        int x = b[l - 1] + b[r] + 2 * n;                              
        cout << 1 << '\n' << *lower_bound(pos[x].begin(), pos[x].end(), l - 1) + 1 << '\n';
      } else {
        int x = b[l] + b[r] + 2 * n;
        cout << 2 << '\n' << l << " " << *lower_bound(pos[x].begin(), pos[x].end(), l) + 1  << '\n';
      }
    }
  }
  return 0;
}