/**
 *  author: milos
 *  created: 04.01.2021 03:19:53
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
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      x += 1;
    } else {
      y += 1;
    }
  }
  if (y >= 1 && x >= 1) {
    sort(a.begin(), a.end());
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";  
  }
  return 0;
}