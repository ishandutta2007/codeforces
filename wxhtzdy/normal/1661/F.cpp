/**
 *    author:  wxhtzdy
 *    created: 15.06.2022 17:31:12
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
  long long m;
  cin >> m;
  for (int i = n - 1; i > 0; i--) {
    a[i] -= a[i - 1];
  }
  auto cost = [&](long long len, long long s) {
    s += 1;
    long long p = len % s;
    long long l1 = (len + s - 1) / s;
    long long l2 = len / s;
    return p * l1 * l1 + (s - p) * l2 * l2; 
  };                         
  auto Check = [&](long long x) {
    long long s = 0;
    for (int i = 0; i < n; i++) {
      int low = 0, high = a[i] - 2;
      while (low <= high) {
        int mid = low + high >> 1;
        if (cost(a[i], mid) - cost(a[i], mid + 1) >= x) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }   
      s += cost(a[i], low);
      if (s > m) {
        return false;
      }
    }                     
    return true;
  };
  long long low = 0, high = 1e18, delta = 0;
  while (low <= high) {
    long long mid = low + high >> 1;
    if (Check(mid)) {
      delta = mid;
      low = mid + 1;
    } else {    
      high = mid - 1;
    }             
  }                     
  long long ans = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int low = 0, high = a[i] - 2;
    while (low <= high) {
      int mid = low + high >> 1;
      if (cost(a[i], mid) - cost(a[i], mid + 1) > delta) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    ans += low;
    sum += cost(a[i], low);
  }
  if (sum > m) {
    ans += (sum - m + delta - 1) / delta;
  }
  cout << ans << '\n';
  return 0;
}

/*
2 3 5
5 / 3  

2 2 1
*/