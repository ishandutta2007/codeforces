/**
 *  author: milos
 *  created: 26.12.2020 12:43:05
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
  int j = n - 1;
  while (j >= 0 && a[j] == a[n - 1]) {
    j--;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == a[n - 1]) {
      ans = max(ans, j - i);   
    } else {
      ans = max(ans, n - 1 - i);
    }
  }
  cout << ans << '\n';
  return 0;
}