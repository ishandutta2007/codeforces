/**
 *  author: milos
 *  created: 06.01.2021 19:57:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = n;
  string k = s;
  vector<int> p(3);
  iota(p.begin(), p.end(), 1);
  map<char, int> id;
  id['R'] = 1;
  id['G'] = 2;
  id['B'] = 3;
  vector<char> c;
  c.push_back('R');
  c.push_back('G');
  c.push_back('B');  
  do {
    string t = s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (p[i % 3] != id[s[i]]) {
        t[i] = c[p[i % 3] - 1];
        cnt += 1;  
      }
    }
    if (cnt < ans) {
      ans = cnt;
      k = t;  
    }
  } while (next_permutation(p.begin(), p.end()));
  cout << ans << '\n' << k << '\n';
  return 0;
}