/**
 *    author:  wxhtzdy
 *    created: 15.10.2022 16:32:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    cout << (mx == 1 ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}