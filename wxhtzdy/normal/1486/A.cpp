/**
 *    author:  milos
 *    created: 18.02.2021 21:32:12       
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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long s = 0, t = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      s += a[i];
      t += i;
      if (s < t) {
        ok = false; 
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}