/**
 *    author:  milos
 *    created: 23.03.2021 08:51:17       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto Transform = [&](string s) {
    vector<char> ans;
    for (char c : s) {
      if (c == '-' || c == ';' || c == '_') {
        continue;
      }
      if (c >= 'a') {
        ans.push_back(c);
      } else {
        ans.push_back((char) (c + 'a' - 'A'));
      }
    }
    return ans;
  };
  vector<string> s(3);
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    //s[i] = Transform(s[i]);
  }                             
  map<vector<char>, bool> was;
  vector<int> id(3);
  iota(id.begin(), id.end(), 0);
  do {
    vector<char> tmp;
    for (int i : id) {
      auto s1 = Transform(s[i]);
      for (char c : s1) {
        tmp.push_back(c);
      }
    }
    was[tmp] = true;
  } while (next_permutation(id.begin(), id.end()));
  int n;
  cin >> n;                   
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    auto t1 = Transform(t);
    cout << (was[t1] ? "ACC" : "WA") << '\n';  
  }
  return 0;
}