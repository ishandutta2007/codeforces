/**
 *    author:  tourist
 *    created: 22.07.2021 17:35:02       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int ans = 11;
    for (int t = 0; t < (1 << 10); t++) {
      bool ok = true;
      for (int i = 0; i < 10; i++) {
        int a = ((t >> i) & 1);
        int b = (s[i] == '0' ? 0 : (s[i] == '1' ? 1 : -1));
        if (b == 1 - a) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        continue;
      }
      int x = 0;
      int y = 0;
      int Lx = 5;
      int Ly = 5;
      int shots = 0;
      for (int i = 0; i < 10; i++) {
        int a = ((t >> i) & 1);
        if (i % 2 == 0) {
          x += a;
          Lx -= 1;
        } else {
          y += a;
          Ly -= 1;
        }
        ++shots;
        if (x + Lx < y || y + Ly < x) {
          break;
        }
      }
      ans = min(ans, shots);
    }
    cout << ans << '\n';
  }
  return 0;
}