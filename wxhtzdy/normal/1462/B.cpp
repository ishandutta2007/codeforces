/**
 *  author: milos
 *  created: 15.12.2020 15:38:51
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
    string s;
    cin >> s;                

    bool ok = 0;
    if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') ok = 1;
    if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n - 1] == '0') ok = 1;
    if (s[0] == '2' && s[1] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ok = 1;
    if (s[0] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ok = 1;
    if (s[n - 4] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ok = 1;
    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
  return 0;
}