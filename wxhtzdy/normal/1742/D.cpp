/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 16:39:29
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
    const int MAX = 1005;
    vector<int> mx(MAX, -2 * n - MAX * MAX);
    for (int i = 0; i < n; i++) {
      mx[a[i]] = i + 1;
    }
    vector<int> ones;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
        ones.push_back(i);
      }
    }                        
    int ans = max(-1, 2 * mx[1]);
    for (int i = 1; i < MAX; i++) {
      for (int j = i + 1; j < MAX; j++) {
        if (__gcd(i, j) == 1) {
          ans = max(ans, mx[i] + mx[j]);
        }
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}