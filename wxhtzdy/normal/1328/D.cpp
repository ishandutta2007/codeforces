/**
 *  author: milos
 *  created: 12.01.2021 02:19:34
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
    if (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end())) {
      cout << 1 << '\n';
      for (int i = 0; i < n; i++) {
        cout << 1 << " ";
      }
      cout << '\n';
      continue;
    }
    if (n % 2 == 0) {
      cout << 2 << '\n';
      for (int i = 0; i < n; i++) {
        cout << i % 2 + 1 << " " ;
      }
      cout << '\n';
      continue;
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (a[i] == a[(i + 1) % n]) ok = true;
    }
    if (ok) {
      cout << 2 << '\n';
      bool was = false;
      vector<int> ans(n, 1);
      for (int i = 0; i < n; i++) {
        if (a[i] == a[i - 1]) was = true;
        ans[i] = (i + was) % 2;  
      }
      for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
      }
      cout << '\n';
      continue;
    }
    cout << 3 << '\n';
    for (int i = 0; i < n - 1; i++) {
      cout << i % 2 + 1 << " ";
    }
    cout << 3 << '\n';
  }
  return 0;
}