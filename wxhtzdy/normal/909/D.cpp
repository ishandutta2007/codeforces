/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 11:26:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<pair<char, int>> f;
  for (int i = 0; i < n; i++) {
    f.emplace_back(s[i], 1);
  }
  auto Merge = [&](vector<pair<char, int>> v) {
    vector<pair<char, int>> ret;
    int bal = 0;
    int sz = (int) v.size();
    for (int i = 0; i < sz; i++) {
      bal += v[i].second;
      if (i + 1 == sz || v[i].first != v[i + 1].first) { 
        ret.emplace_back(v[i].first, bal);
        bal = 0;
      }       
    }
    return ret;
  };
  f = Merge(f);
  int ans = 0;
  while ((int) f.size() > 1) {
    for (int i = 0; i + 1 < (int) f.size(); i++) {
      f[i].second -= 1;
      f[i + 1].second -= 1;
    }
    vector<pair<char, int>> tmp;
    for (int i = 0; i < (int) f.size(); i++) {
      if (f[i].second > 0) {
        tmp.push_back(f[i]);
      }
    }
    f = Merge(tmp);
    ans += 1;
  }
  cout << ans << '\n';                                                                      
  return 0;
}