/**
 *    author:  wxhtzdy
 *    created: 08.09.2022 17:04:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  vector<long long> f0(n + 1);
  vector<long long> f1(n + 1);
  {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += b[i];
    }
    multiset<int> d;
    for (int i = 0; i < n; i++) {
      d.insert(a[i] - b[i]); 
    }
    f0[0] = sum;
    for (int i = 1; i <= n; i++) {
      sum += *prev(d.end());
      d.erase(prev(d.end()));
      f0[i] = sum;
    }
  }
  {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }
    multiset<int> d;
    for (int i = 0; i < n; i++) {
      d.insert(b[i] - a[i]); 
    }
    f1[0] = sum;
    for (int i = 1; i <= n; i++) {
      sum += *prev(d.end());
      d.erase(prev(d.end()));
      f1[i] = sum;
    }
  }
  int q;
  cin >> q;
  map<pair<int, int>, long long> mp;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (mp.count({x, y})) {
      cout << mp[{x, y}] << '\n';
      continue;
    }
    long long ans = -1;
    if (x > y) {    
      for (int i = 0; i * x <= n; i++) {
        if ((n - i * x) % y == 0) {
          ans = max(ans, f0[i * x]);   
        }
      } 
    } else {
      for (int i = 0; i * y <= n; i++) {
        if ((n - i * y) % x == 0) {
          ans = max(ans, f1[i * y]);
        }
      }
    }
    mp[{x, y}] = ans;
    cout << ans << '\n';
  }                                             
  return 0;
}