/**
 *    author:  wxhtzdy
 *    created: 08.09.2022 16:34:37
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
    int idx = max_element(a.begin(), a.end()) - a.begin();
    cout << idx + 1 << '\n';
  }                                                                    
  return 0;
}