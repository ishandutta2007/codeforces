/**
 *    author:  milos
 *    created: 01.08.2021 07:46:23       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;                                 
  string s;
  cin >> s;
  vector<vector<vector<int>>> pref(n + 1, vector<vector<int>>(3, vector<int>(3)));
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i];
    pref[i + 1][i % 3][(int) (s[i] - 'a')]++;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int mn = n;          
    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
          if (x != y && x != z && y != z) {
            int curr = r - l + 1;
            curr -= pref[r][0][x] - pref[l - 1][0][x];
            curr -= pref[r][1][y] - pref[l - 1][1][y];
            curr -= pref[r][2][z] - pref[l - 1][2][z];
            mn = min(mn, curr); 
          }
        }
      }
    }
    cout << mn << '\n';
  }
  return 0;
}