/**
 *    author:  wxhtzdy
 *    created: 24.08.2022 21:18:40
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
  int x = *min_element(a.begin(), a.end());
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (a[i] % x != 0) {
      ok = false;
    }
  }
  cout << (ok ? x : -1) << '\n';                                       
  return 0;
}