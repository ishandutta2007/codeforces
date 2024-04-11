/**
 *    author:  wxhtzdy
 *    created: 19.09.2022 16:33:44
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
    for (int i = 0; i < k; i++) {
      vector<int> b;
      for (int j = i; j < n; j += k) {
        b.push_back(a[j]);
      }              
      sort(b.rbegin(), b.rend());
      int ptr = 0;
      for (int j = i; j < n; j += k) {
        a[j] = b[ptr];
        ptr += 1;
      }
    }
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      ans += a[i];
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}