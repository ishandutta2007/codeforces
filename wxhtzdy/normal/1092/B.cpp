/**
 *    author:  milos
 *    created: 23.01.2021 20:40:33       
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
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 1; i < n; i += 2) {
    ans += a[i] - a[i - 1];
  }
  cout << ans << '\n';
  return 0;
}