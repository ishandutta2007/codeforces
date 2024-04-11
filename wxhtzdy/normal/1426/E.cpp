/**
 *  author: milos
 *  created: 02.01.2021 13:25:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(3), b(3);
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> b[i];
  }
  int mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
  int mn = max({0, a[0] - b[0] - b[2], a[1] - b[0] - b[1], a[2] - b[1] - b[2]});
  cout << mn << " " << mx << '\n';
  return 0;
}