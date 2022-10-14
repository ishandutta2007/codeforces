/**
 *  author: milos
 *  created: 30.12.2020 21:34:39
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
    set<int> s;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        s.insert(a[j] - a[i]);
      }
    }
    cout << (int) s.size() << '\n';
  }
  return 0;
}