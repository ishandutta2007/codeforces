/**
 *  author: milos
 *  created: 26.09.2020 19:13:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.rbegin(), a.rend());
    int ans = 0;
    if (a[0] >= 1) ans++, a[0]--;
    if (a[1] >= 1) ans++, a[1]--;
    if (a[2] >= 1) ans++, a[2]--;    
    if (a[0] >= 1 && a[1] >= 1) ans++, a[0]--, a[1]--;
    if (a[0] >= 1 && a[2] >= 1) ans++, a[0]--, a[2]--;
    if (a[1] >= 1 && a[2] >= 1) ans++, a[1]--, a[2]--;
    if (a[0] >= 1 && a[1] >= 1 && a[2] >= 1) ans++;
    cout << ans << '\n';
  }
  return 0;
}