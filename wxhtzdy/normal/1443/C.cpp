/**
 *  author: milos
 *  created: 02.11.2020 15:49:30
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
    vector<pair<long long, long long>> a(n);        
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i].second;
    }
    /*auto Can = [&](long long x) {
      long long cnt = 0, mx = 0;
      for (int i = 0; i < n; i++) {
        if (a[i].first <= x) {
          mx = max(mx, a[i].first);
        } else {
          
        }
      }
    };*/
    /*long long low = 0, high = 1e9;
    for (int i = 0; i < 100; i++) {
      long long mid = (low + high) / 2;
      if (Can(mid)) {
        high = mid;
      } else {
        low = mid;
      }
      }*/
    sort(a.rbegin(), a.rend());
    long long ans = a[0].first, sum = 0;
    for (int i = 0; i < n; i++) {
      //cout << a[i].first << " " << a[i].second << '\n';
      ans = min(ans, max(a[i].first, sum));
      sum += a[i].second;  
    }
    ans = min(ans, sum);
    cout << ans << '\n'; 
  }
  return 0;
}