/**
 *    author:  milos
 *    created: 30.03.2021 20:45:39       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;   
  while (tt--) {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];  
    }
    vector<int> all;
    for (int i = 0; i < n; i++) {
      int new_h = h[i] % (a + b);
      if (new_h > 0 && new_h <= a) {
        all.push_back(0);
      } else {
        if (new_h == 0) {
          all.push_back((b + a - 1) / a);
        } else {
          new_h -= a;
          all.push_back((new_h + a - 1) / a);
        }
      }
    }
    sort(all.begin(), all.end());
    int ans = 0;
    for (int i : all) {
      if (k >= i) {
        ans += 1;
        k -= i;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}