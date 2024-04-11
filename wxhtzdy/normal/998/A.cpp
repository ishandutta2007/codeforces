/**
 *    author:  milos
 *    created: 07.02.2021 20:03:52       
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
  if (n == 1 || (n == 2 && a[0] == a[1])) {
    cout << -1 << '\n';
    return 0;
  }
  int mn = *min_element(a.begin(), a.end());
  cout << n - 1 << '\n';
  for (int i = 0; i < n; i++) {
    if (a[i] == mn) {
      mn = -1;
      continue;
    }
    cout << i + 1 << " ";
  }
  return 0;
}