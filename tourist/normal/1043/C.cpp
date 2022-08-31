/**
 *    author:  tourist
 *    created: 28.10.2018 18:39:35       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int len = (int) s.size();
  vector<int> for_mn(len, 0);
  char c = 'b';
  for (int i = len - 1; i >= 0; i--) {
    if (s[i] != c) {
      for_mn[i] = 1;
      c = (c == 'a' ? 'b' : 'a');
    }
  }
  for (int i = 0; i < len; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << for_mn[i];
  }
  cout << '\n';
  return 0;
}