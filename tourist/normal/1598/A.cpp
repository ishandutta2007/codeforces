/**
 *    author:  tourist
 *    created: 10.10.2021 12:04:08       
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
    string a;
    cin >> a;
    string b;
    cin >> b;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '1') {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}