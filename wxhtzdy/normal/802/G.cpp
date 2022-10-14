#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string t = "heidi";
  int nxt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[nxt]) {
      nxt++;
    }
    if (nxt == t.size()) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}