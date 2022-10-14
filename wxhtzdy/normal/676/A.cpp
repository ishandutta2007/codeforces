/**
 *  author: milos
 *  created: 16.12.2020 02:09:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int low = 0, high = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      low = i;
    }
    if (a[i] == n) {
      high = i;  
    }
  }
  cout << max(max(high, low), n - min(low, high) - 1) << '\n';
  return 0;
}