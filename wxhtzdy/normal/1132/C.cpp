/**
 *  author: milos
 *  created: 15.12.2020 08:00:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> q >> n;
  vector<int> cnt(q + 1, 0);
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    for (int j = l[i]; j <= r[i]; j++) {
      cnt[j]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int p = 0;
    for (int j = l[i]; j <= r[i]; j++) {
      cnt[j]--;
    }
    for (int j = 0; j <= q; j++) {
      if (cnt[j] > 0) {
        p++;
      }
    }
    vector<int> pref(q + 1, 0);
    for (int j = 1; j <= q; j++) {
      pref[j] = pref[j - 1];
      if (cnt[j] == 1) {
        pref[j]++;
      }
    }              
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }    
      ans = max(ans, p - (pref[r[j]] - pref[l[j] - 1]));
    }
    for (int j = l[i]; j <= r[i]; j++) {
      cnt[j]++;
    }
  }   
  cout << ans << '\n';
  return 0;
}