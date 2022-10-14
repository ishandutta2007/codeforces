#include <bits/stdc++.h>

using namespace std;

string keys = "qwertyuiopasdfghjkl;zxcvbnm,./";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  char mv;
  cin >> mv;
  string s;
  cin >> s;
  int n = (int) s.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int) keys.size(); j++) {
      if (s[i] == keys[j]) {
        if (mv == 'R') {
          cout << keys[j - 1];
        } else {
          cout << keys[j + 1];
        }
      }
    }
  }
  return 0;
}