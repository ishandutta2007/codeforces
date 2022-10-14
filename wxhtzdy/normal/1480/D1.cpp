/**
 *    author:  milos
 *    created: 07.02.2021 16:15:45       
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
  // 1 1 2 1 3 1
  int x = 0, y = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      if (x != a[i] || y != a[i]) {
        ans++;
      }
      continue;
    }    
    if (x == a[i] && y == a[i]) {
      continue;
    }
    if (x == a[i]) {
      y = a[i];
      ans++;
      continue;
    }
    if (y == a[i]) {
      x = a[i];
      ans++;
      continue;
    }    
    if (y == a[i + 1]) {
      y = a[i];
      ans++;
      continue;
    } else {
      ans++;
      x = a[i];
      continue;
    }
  }
  cout << ans << '\n';
  return 0;
}