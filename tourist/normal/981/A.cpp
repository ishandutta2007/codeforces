/**
 *    author:  tourist
 *    created: 27.05.2018 17:49:32       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string t = s;
  reverse(t.begin(), t.end());
  if (s != t) {
    cout << (int) s.length() << '\n';
    return 0;
  }
  if (s == string(s.length(), s[0])) {
    cout << 0 << '\n';
    return 0;
  }
  cout << (int) s.length() - 1 << '\n';
  return 0;
}