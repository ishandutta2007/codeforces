/**
 *    author:  milos
 *    created: 22.08.2021 12:25:11       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  cout << (accumulate(a.begin(), a.end(), 0) >= accumulate(b.begin(), b.end(), 0) ? "Yes" : "No") << '\n';
  return 0;
}