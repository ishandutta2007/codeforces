/**
 *    author:  milos
 *    created: 10.03.2021 13:08:32       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == 2 * k) {
      cout << "NO" << '\n';
      continue;
    }             bool ok = true;
    for (int i = 0; i < k; i++) {
      if (s[i] != s[n - i - 1]) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}