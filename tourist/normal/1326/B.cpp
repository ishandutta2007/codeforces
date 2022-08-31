/**
 *    author:  tourist
 *    created: 19.03.2020 17:38:04       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }                  
  vector<int> a(n);
  int x = 0;
  for (int i = 0; i < n; i++) {
    a[i] = b[i] + x;
    x = max(x, a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << '\n';
  return 0;
}