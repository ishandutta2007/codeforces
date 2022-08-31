/**
 *    author:  tourist
 *    created: 20.04.2019 21:04:34       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int cnt = 0;
  for (char c : s) {
    cnt += (c == 'a');
  }
  cout << min((int) s.size(), 2 * cnt - 1) << '\n';
  return 0;
}