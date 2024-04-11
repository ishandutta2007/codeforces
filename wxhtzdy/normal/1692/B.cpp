/**
 *    author:  wxhtzdy
 *    created: 14.06.2022 17:15:48
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
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
    }       
    vector<int> c(2);
    for (auto &p : cnt) {
      c[p.second & 1] += 1;
    }
    int ans = c[1] + c[0] - (c[0] % 2);
    cout << ans << '\n';
  }                                                                    
  return 0;
}