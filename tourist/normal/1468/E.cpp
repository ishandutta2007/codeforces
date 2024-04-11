/**
 *    author:  tourist
 *    created: 25.12.2020 14:44:42       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    vector<int> a(4);
    for (int i = 0; i < 4; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[0] * a[2] << '\n';
  }
  return 0;
}