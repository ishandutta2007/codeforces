/**
 *    author:  tourist
 *    created: 04.01.2019 17:33:54       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < 5; i++) {
    string t;
    cin >> t;
    if (s[0] == t[0] || s[1] == t[1]) { cout << "YES" << '\n'; return 0; }
  }
  cout << "NO" << '\n';
  return 0;
}