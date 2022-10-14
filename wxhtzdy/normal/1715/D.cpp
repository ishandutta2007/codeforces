/**
 *    author:  wxhtzdy
 *    created: 22.08.2022 15:44:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, q;
  cin >> n >> q;
  vector<array<int, 3>> qs(q);
  for (int i = 0; i < q; i++) {
    cin >> qs[i][0] >> qs[i][1] >> qs[i][2];
    --qs[i][0]; --qs[i][1];
  }
  vector<int> ans(n);
  for (int b = 0; b < 30; b++) {
    vector<int> nans(n, 1);
    vector<vector<int>> at(n);
    for (int i = 0; i < q; i++) {
      if (qs[i][2] >> b & 1) {
        at[qs[i][0]].push_back(qs[i][1]);
        at[qs[i][1]].push_back(qs[i][0]);
      } else {
        nans[qs[i][0]] = 0;
        nans[qs[i][1]] = 0;                    
      }           
    }
    for (int i = 0; i < n; i++) {
      bool ok = true;
      for (int j : at[i]) {
        if (nans[j] == 0 || j == i) {
          ok = false;
        }
      }
      if (ok) {
        nans[i] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      ans[i] += (1 << b) * nans[i];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}