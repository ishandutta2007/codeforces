/**
 *  author: milos
 *  created: 14.12.2020 11:33:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1] + 1) {
        cnt++;
        break;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}