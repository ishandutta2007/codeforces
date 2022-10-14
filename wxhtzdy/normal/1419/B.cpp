/**
 *    author:  milos
 *    created: 17.03.2021 07:43:42       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<long long> good;
  good.push_back(1LL);
  for (int i = 0; i < 30; i++) {
    long long a = good.back();
    good.push_back(a * 2 + 1);  
  }
  int tt;
  cin >> tt;
  while (tt--) {
    long long x;
    cin >> x; 
    int ans = 0;
    for (int i = 0; i < (int) good.size(); i++) {
      long long s = good[i] * (good[i] + 1) / 2;
      if (x >= s) {
        ans++;
        x -= s;
      }                             
    }
    cout << ans << '\n';
  }
  return 0;
}