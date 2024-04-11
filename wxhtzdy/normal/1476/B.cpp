/**
 *    author:  milos
 *    created: 29.01.2021 15:59:39       
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
    double k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto Can = [&](long long x) {
      auto b = a;
      b[0] += x;     
      double sum = 0;
      for (int i = 0; i < n; i++) {
        if (i == 0) {
          sum += b[i];
          continue;    
        }
        double p = b[i] / sum;
        if (b[i] * 100 > k * sum) {
          return false;
        }       
        sum += b[i];
      }
      return true;
    };
    long long inf = (long long) 1e11;
    long long bot = 0LL, top = inf, ans = inf;
    while (bot <= top) {
      long long mid = bot + top >> 1;
      if (Can(mid)) {
        ans = mid;
        top = mid - 1;      
      } else {
        bot = mid + 1;
      }
    }
    cout << ans << '\n';  
  }
  return 0;
}