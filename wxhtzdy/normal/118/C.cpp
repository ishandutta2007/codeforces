/**
 *    author:  milos
 *    created: 10.03.2021 22:27:05       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    b.push_back((int) (s[i] - '0'));
  }
  vector<vector<int>> pos(10);
  for (int i = 0; i < n; i++) {
    pos[b[i]].push_back(i);
  }
  pair<int, string> ans = {1e9, s};
  for (int i = 0; i < 10; i++) {
    vector<pair<int, int>> a;
    for (int j = 1; j < 10; j++) {
      if (i + j < 10) {  
        for (int p : pos[i + j]) {
          a.emplace_back(j, p);
        }
      }
      if (i >= j) {
        reverse(pos[i - j].begin(), pos[i - j].end());
        for (int p : pos[i - j]) {
          a.emplace_back(j, p);
        }  
        reverse(pos[i - j].begin(), pos[i - j].end());
      }
    }
    int need = k - (int) pos[i].size();
    int nans = 0;
    for (int j = 0; j < need; j++) {
      nans += a[j].first;
    }
    string t = s;
    for (int j = 0; j < need; j++) {
      t[a[j].second] = (char) (i + '0');
    }
    if (ans.first > nans || (ans.first == nans && t < ans.second)) {
      ans.first = nans;
      ans.second = t;
    }
  }
  cout << ans.first << '\n' << ans.second << '\n';
  return 0;
}