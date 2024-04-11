/**
 *    author:  milos
 *    created: 03.08.2021 15:41:46       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> pos;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      pos.push_back(i);
    }
  }
  set<int> x;
  for (int i = 1; i < (int) pos.size(); i++) {
    x.insert(pos[i] - pos[i - 1]);
  }
  cout << ((int) x.size() <= 1 ? "YES" : "NO") << '\n';
  return 0;
}