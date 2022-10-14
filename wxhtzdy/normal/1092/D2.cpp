/**
 *    author:  milos
 *    created: 23.01.2021 21:09:39       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  vector<int> b;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (a[i] == mx) {
      continue;
    }
    int j = i - 1;
    while (j < n - 1 && a[j + 1] != mx) {
      j += 1;                   
      if ((int) b.size() > 0 && a[j] == b.back()) {
        b.pop_back();
      } else {
        if ((int) b.size() == 0 || a[j] < b.back()) {
          b.push_back(a[j]);
        } else {
          ok = false;
          break;
        }
      }
    }
    if ((int) b.size() > 0) {
      ok = false;
      break;
    }
    swap(i, j);
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}