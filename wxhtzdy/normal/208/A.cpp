#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.length();
  vector<string> v;
  string a = "";
  for (int i = 0; i < n; i++) {
    if (i < n - 2 && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
      if (a != "") {
        v.push_back(a);
      }
      a = "";
      i += 2;
      continue;
    }
    a += s[i];
  }
  if (a != "") {
    v.push_back(a);
  }
  for (int i = 0; i < (int) v.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << v[i];
  }
  return 0;   
}