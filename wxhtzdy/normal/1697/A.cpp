/**
 *    author:  wxhtzdy
 *    created: 13.06.2022 15:55:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int s = accumulate(a.begin(), a.end(), 0);
    cout << max(0, s - m) << '\n';
  }                                                                    
  return 0;
}