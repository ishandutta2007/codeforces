/**
 *    author:  SigmaMale06
 *    created: 25.05.2022 19:33:30
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
    int sum = accumulate(a.begin(), a.end(), 0);
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (a[i] * n == sum) {
        ok = true;
      }
    }                     
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}