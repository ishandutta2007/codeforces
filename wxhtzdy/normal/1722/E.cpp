/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 15:37:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    const int MAX = 1005;
    vector<vector<long long>> pref(MAX, vector<long long>(MAX));
    for (int i = 0; i < n; i++) {
      int h, w;
      cin >> h >> w;
      pref[h][w] += h * w;
    }                       
    for (int i = 1; i < MAX; i++) {
      for (int j = 1; j < MAX; j++) {
        pref[i][j] += pref[i][j - 1];
      }
    }         
    while (q--) {
      int hs, ws, hb, wb;
      cin >> hs >> ws >> hb >> wb;
      long long ans = 0;
      for (int i = hs + 1; i < hb; i++) {
        ans += pref[i][wb - 1] - pref[i][ws];
      }
      cout << ans << '\n';
    }
  }                                                                    
  return 0;
}