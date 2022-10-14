/**
 *  author: milos
 *  created: 04.01.2021 03:15:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (a[0] == a.back()) {
    cout << -1 << '\n';
  } else {
    for (int i = 0; i < 2 * n; i++) {
      cout << a[i] << " ";
    }
  }
  return 0;
}