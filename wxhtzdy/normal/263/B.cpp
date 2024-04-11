/**
 *  author: milos
 *  created: 31.12.2020 22:46:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (k > n) {
    cout << -1 << '\n';
    return 0;
  }
  sort(a.begin(), a.end());
  if (k == n) {
    cout << 1 << " " << 1 << '\n';
    return 0;
  }
  if (a[n - k] == a[n - k - 1]) {
    cout << -1 << '\n';  
  } else {
    cout << a[n - k] << " " << a[n - k] << '\n';
  }
  return 0;
}