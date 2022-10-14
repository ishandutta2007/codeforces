/**
 *    author:  milos
 *    created: 03.09.2021 16:13:35       
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
    vector<int> a(n + 1);
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
    while (q--) {
      int l, r;
      cin >> l >> r; 
      if (b[r] == b[l - 1]) {
        cout << 0 << '\n';
      } else {
        cout << (r - l) % 2 + 1 << '\n';
      }
    }
  }
  return 0;
}