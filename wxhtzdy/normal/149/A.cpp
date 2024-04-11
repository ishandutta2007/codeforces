/**
 *    author:  milos
 *    created: 27.01.2021 17:37:53       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  vector<int> a(12);
  for (int i = 0; i < 12; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  int s = 0;
  if (k == 0) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < 12; i++) {
    s += a[i];
    if (s >= k) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}