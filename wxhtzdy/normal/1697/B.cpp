/**
 *    author:  wxhtzdy
 *    created: 13.06.2022 15:57:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<long long> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << pref[n - x + y] - pref[n - x] << '\n';
  }                     
  return 0;
}