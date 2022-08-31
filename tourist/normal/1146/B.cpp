/**
 *    author:  tourist
 *    created: 20.04.2019 21:06:17       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  int cnt = 0;
  for (char c : s) {
    cnt += (c == 'a');
  }
  if ((n - cnt) % 2 != 0) {
    cout << ":(" << '\n';
    return 0;
  }
  string t = s.substr(0, cnt + (n - cnt) / 2);
  string w = t;
  for (char c : t) {
    if (c != 'a') {
      w += c;
    }
  }
  cout << (w == s ? t : ":(") << '\n';
  return 0;
}