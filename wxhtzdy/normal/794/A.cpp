/**
 *    author:  milos
 *    created: 25.09.2021 12:32:35       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (b < x[i] && x[i] < c) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}