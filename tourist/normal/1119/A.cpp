/**
 *    author:  tourist
 *    created: 06.04.2019 12:35:31       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != a[0]) {
      ans = max(ans, i - 0);
    }
    if (a[i] != a[n - 1]) {
      ans = max(ans, n - 1 - i);
    }
  }
  cout << ans << '\n';
  return 0;
}