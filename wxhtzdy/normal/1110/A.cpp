/**
 *  author: milos
 *  created: 29.12.2020 13:17:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> k >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }         
  int sum = a[n - 1] % 2;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] % 2 == 1 && k % 2 == 1) {
      sum ^= 1;
    }
  }
  cout << (sum == 0 ? "even" : "odd") << '\n';
  return 0;
}