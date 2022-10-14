/**
 *    author:  milos
 *    created: 17.03.2021 07:55:20       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    long long s = 0;
    bool diff = false;
    bool same = false;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i] - x;
      if (a[i] != x) {
        diff = true;
      }
      if (a[i] == x) {
        same = true;
      }
    }
    if (!diff) {
      cout << 0 << '\n';
    } else {
      if (s == 0LL || same) {
        cout << 1 << '\n';
      } else {
        cout << 2 << '\n';
      }
    }
  }
  return 0;
}