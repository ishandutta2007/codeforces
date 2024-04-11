/**
 *    author:  tourist
 *    created: 01.04.2021 17:38:01       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int ans = (s[0][0] == '*');
  int i = 0;
  int j = 0;
  while (i < h - 1 || j < w - 1) {
    if (j == w - 1 || (i < h - 1 && s[i + 1][j] == '*')) {
      i += 1;
    } else {
      j += 1;
    }
    ans += (s[i][j] == '*');
  }
  cout << ans << '\n';
  return 0;
}