/**
 *    author:  milos
 *    created: 20.09.2021 21:19:24       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  int m;
  cin >> m;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    auto it = lower_bound(a.begin(), a.end(), x);
    const long long inf = LLONG_MAX;
    long long ans = inf;
    if (it != a.end()) {
      ans = min(ans, max(0LL, y - (sum - *it)));
    }
    if (it != a.begin()) {
      ans = min(ans, max(0LL, y - (sum - *prev(it))) + x - *prev(it)); 
    }
    cout << ans << '\n';
  }
  return 0;
}