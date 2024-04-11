/**
 *    author:  tourist
 *    created: 04.01.2019 17:46:25       
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
  for (int t = 0; t < (1 << n); t++) {
    int x = 0;
    for (int i = 0; i < n; i++) {
      if (t & (1 << i)) x += a[i];
      else x -= a[i];
    }
    if (x % 360 == 0) { cout << "YES" << '\n'; return 0; }
  }
  cout << "NO" << '\n';
  return 0;
}