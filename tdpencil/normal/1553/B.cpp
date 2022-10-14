#include <bits/stdc++.h>
using namespace std;

void gogo() {
  string s, t;
  cin >> s >> t;

  // iterate over substr of s
  // then go back
  bool f = 0;
  reverse(s.begin(), s.end());
  for (int i = 0; i < int(s.size()); i++) {
    string cur;
    for (int j = i; j < int(s.size()); j++) {
      cur += s[j];
      if (cur == t) f = 1;
    }
  }
  reverse(s.begin(), s.end());

  for (int i = 0; i < (int)s.size(); i++) {
    string cur;

    for (int j = i; j < (int)s.size(); j++) {
      
      // continue;
      cur += s[j];
      // iterate back
      bool can = 1;
      int other = int(t.size()) - int(cur.size());
      if (other < 0) {
        continue;
      }
      // continue;
      for (int k = 0; k < cur.size(); k++) {
        can &= cur[k] == t[k];
      }
      // continue;
      int ptr = cur.size();
      // continue;
      while (ptr < t.size()) {
        
        if (j - (ptr - int(cur.size()) + 1) >= 0 &&
            t[ptr] == s[j - (ptr - int(cur.size()) + 1)])
          ptr++;
        else
          break;
      }
      if (ptr == t.size()) f |= can;
    }
  }

  cout << (f ? "YES" : "NO") << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    gogo();
  }
}