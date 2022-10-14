/**
 *  author: milos
 *  created: 13.12.2020 11:57:44
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
  bool ok = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] > a[i] && a[i + 1] < a[i] * 2) ok = 0;
  }
  cout << (ok ? "NO" : "YES") << '\n';
  return 0;
}