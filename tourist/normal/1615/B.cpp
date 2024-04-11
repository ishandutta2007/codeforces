/**
 *    author:  tourist
 *    created: 24.12.2021 17:35:03       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int K = 30;
  const int N = (int) 2e5 + 10;
  vector<vector<int>> pref(K, vector<int>(N + 1));
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < N; j++) {
      pref[i][j + 1] = pref[i][j] + ((j & (1 << i)) ? 0 : 1);
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    int res = r - l + 1;
    for (int i = 0; i < K; i++) {
      res = min(res, pref[i][r + 1] - pref[i][l]);
    }
    cout << res << '\n';
  }
  return 0;
}