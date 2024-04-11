/**
 *  author: milos
 *  created: 15.09.2020 00:55:32
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    } 
    vector<int> v;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (b[i] == 0) {
        v.push_back(a[i]);
      }
    }
    sort(v.rbegin(), v.rend());
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] == 0) {
        a[i] = v[j];
        j++;  
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}