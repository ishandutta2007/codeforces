/**
 *    author:  milos
 *    created: 10.02.2021 08:35:14       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = (int) 1e9;
    int cnt = 0;
    map<int, int> c;
    function<void(int)> Add = [&](int x) {
      if (c[x] == 0) {
        cnt++;
      }
      c[x]++;
    };         
    function<void(int)> Remove = [&](int x) {
      if (c[x] == 1) {
        cnt--;
      }
      c[x]--;
    };
    for (int i = 0; i < n; i++) {
      Add(a[i]);
      if (i >= d) {
        Remove(a[i - d]);
        ans = min(ans, cnt);
      }
      if (i == d - 1) {
        ans = min(ans, cnt);
      }         
    }
    ans = min(ans, cnt);
    cout << ans << '\n';
  }
  return 0;
}