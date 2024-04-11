/**
 *    author:  milos
 *    created: 07.06.2021 20:41:00       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = -1, ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i] - 1);
    if (mx == i) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}