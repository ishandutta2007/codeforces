/**
 *  author: milos
 *  created: 07.01.2021 17:03:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<long long> pref(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      pref[i] = a[i];
    } else {
      pref[i] = pref[i - 1] + a[i];
    }
  }
  vector<long long> ans(n);  
  for (int i = 0; i < n; i++) {
    if (i < m) {
      ans[i] = pref[i];
    } else {
      ans[i] = pref[i] + ans[i - m];
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  return 0;
}