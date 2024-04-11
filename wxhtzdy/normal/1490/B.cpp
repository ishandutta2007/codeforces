/**
 *    author:  milos
 *    created: 16.02.2021 16:46:52       
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
    vector<int> cnt(3, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i] % 3]++;
    }      
    int x = n / 3;
    int ans = 0;                
    if (cnt[0] < x) {
      int diff = x - cnt[0];
      ans += diff, cnt[2] -= diff;
    } else {
      int diff = cnt[0] - x;
      ans += diff, cnt[1] += diff;
    }                      
    int diff = abs(cnt[1] - x);
    if (cnt[1] < x) diff *= 2;
    ans += diff;
    cout << ans << '\n';
  }
  return 0;
}