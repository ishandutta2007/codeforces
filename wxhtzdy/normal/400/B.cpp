/**
 *    author:  milos
 *    created: 08.02.2021 11:12:34       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  set<int> diff;
  for (int i = 0; i < n; i++) {
    int x, y;
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'G') {
        x = j;
      }
      if (s[i][j] == 'S') {
        y = j;
      }
    }          
    if (y < x) {
      cout << -1 << '\n';
      return 0;
    }
    diff.insert(x - y);
  }
  cout << (int) diff.size() << '\n';
  return 0;
}