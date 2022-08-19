/**
 *    author:  tourist
 *    created: 01.04.2021 17:46:18       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 2; i < (int) s.size(); i++) {
    int x = (int) (s[i - 2] - 'A');
    int y = (int) (s[i - 1] - 'A');
    int z = (int) (s[i - 0] - 'A');
    if ((x + y) % 26 != z) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  return 0;
}