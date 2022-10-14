/**
 *  author: milos
 *  created: 05.01.2021 19:55:22
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
      a[i] -= 1;
    }   
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (i >= m) {
        ans += b[a[i]];
      } else {
        ans += min(b[i], b[a[i]]);      
      }
    }
    cout << ans << '\n';
  }
  return 0;
}