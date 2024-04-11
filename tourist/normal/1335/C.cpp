/**
 *    author:  tourist
 *    created: 13.04.2020 17:37:41       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      --x;
      ++cnt[x];
    }
    int mx = *max_element(cnt.begin(), cnt.end());
    int cc = 0;
    for (int i = 0; i < n; i++) {
      cc += !!cnt[i];
    }
    cout << min(mx, cc) - (mx == cc) << '\n';
  }
  return 0;
}