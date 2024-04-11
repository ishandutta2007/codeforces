/**
 *  author: milos
 *  created: 11.01.2021 23:28:46
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
      --a[i];
    }
    int j = 0;
    while (j < n) {
      auto it = min_element(a.begin() + j, a.end());  
      int pos = it - a.begin(), val = a[pos];
      a.erase(a.begin() + pos);
      a.insert(a.begin() + j, val);
      if (j == pos) {
        j = pos + 1;
      } else {
        j = pos;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}