/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 16:46:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<long long> pref(n + 1);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
      a[i] = max(a[i], a[i - 1]);
    }   
    while (q--) {
      int x;
      cin >> x;
      int idx = lower_bound(a.begin(), a.end(), x + 1) - a.begin() - 1;  
      cout << pref[idx] << " ";
    }
    cout << '\n';
  }                                                                    
  return 0;
}