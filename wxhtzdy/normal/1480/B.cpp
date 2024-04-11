/**
 *    author:  milos
 *    created: 07.02.2021 15:39:36       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b;
    int n;
    cin >> a >> b >> n;
    long long total = 0LL;
    vector<pair<long long, long long>> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i].first;
    }
    long long mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> x[i].second;
      mx = max(mx, x[i].first);
    }
    for (int i = 0; i < n; i++) {
      total += max(0LL, ((x[i].second + a - 1) / a)) * x[i].first; 
    }
    total -= mx;
    if (total < b) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}