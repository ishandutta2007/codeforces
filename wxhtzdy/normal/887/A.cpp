/**
 *  author: milos
 *  created: 14.01.2021 22:13:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int cnt = 0;               
  int j = 1e9;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '1') {
      j = i;
      break;
    }
  }
  for (int i = j; i < (int) s.size(); i++) {
    cnt += s[i] == '0';
  }
  cout << (cnt >= 6 ? "yes" : "no") << '\n';
  return 0;
}