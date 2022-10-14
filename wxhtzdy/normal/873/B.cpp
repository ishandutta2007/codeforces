/**
 *    author:  milos
 *    created: 25.09.2021 12:20:43       
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
  map<int, int> last;
  map<int, int> was;
  was[0] = 1;
  last[0] = -1;
  int ans = 0, bal = 0;
  for (int i = 0; i < n; i++) {
    bal += (s[i] == '0' ? -1 : 1);
    if (was[bal]) {
      ans = max(ans, i - last[bal]);
    } else {
      was[bal] = 1;
      last[bal] = i;
    }
  }
  cout << ans << '\n'; 
  return 0;
}