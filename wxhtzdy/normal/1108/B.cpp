/**
 *  author: milos
 *  created: 06.01.2021 19:54:24
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
  cout << a[n - 1] << " ";
  for (int i = (int) a.size() - 2; i >= 0; i--) {
    if (a[n - 1] % a[i] != 0 || a[i] == a[i + 1]) {
      cout << a[i] << '\n';
      return 0;
    }
  }
  return 0;
}