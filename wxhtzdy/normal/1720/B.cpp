/**
 *    author:  wxhtzdy
 *    created: 22.08.2022 14:31:31
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
    cout << a[n - 1] + a[n - 2] - a[0] - a[1] << '\n';
  }                                                                    
  return 0;
}