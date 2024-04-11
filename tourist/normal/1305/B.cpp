/**
 *    author:  tourist
 *    created: 03.03.2020 17:36:59       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int len = (int) s.size();
  int pref = 0;
  int suf = 0;
  for (int i = 0; i < len; i++) {
    suf += (s[i] == ')');
  }
  int cut = -1;
  for (int i = 0; i <= len; i++) {
    if (pref == suf) {
      cut = i;
      break;
    }
    if (s[i] == '(') {
      ++pref;
    } else {
      --suf;
    }
  }
  vector<int> pos;
  for (int i = 0; i < cut; i++) {
    if (s[i] == '(') {
      pos.push_back(i);
    }
  }
  for (int i = cut; i < len; i++) {
    if (s[i] == ')') {
      pos.push_back(i);
    }
  }
  if (pos.empty()) {
    cout << 0 << '\n';
  } else {
    cout << 1 << '\n';
    cout << pos.size() << '\n';
    for (int i = 0; i < (int) pos.size(); i++) {
      if (i > 0) cout << " ";
      cout << pos[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}