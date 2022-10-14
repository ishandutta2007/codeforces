/**
 *  author: milos
 *  created: 16.12.2020 09:20:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int u = 0, d = 0, l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') u++;
    if (s[i] == 'D') d++;
    if (s[i] == 'L') l++;
    if (s[i] == 'R') r++;
  }
  cout << min(l, r) * 2 + min(u, d) * 2 << '\n';
  return 0;
}