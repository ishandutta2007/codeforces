/**
 *  author: milos
 *  created: 16.12.2020 09:12:25
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
  for (int i = 1; i < n - 1; i++) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans++;
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans++;
  }
  cout << ans << '\n';
  return 0;
}