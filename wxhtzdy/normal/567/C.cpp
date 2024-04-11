/**
 *    author:  milos
 *    created: 21.02.2021 14:43:28       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }            
  map<long long, int> left, right;
  for (int i = 0; i < n; i++) {
    right[a[i]]++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    right[a[i]]--;
    if (a[i] % k == 0) {
      ans += (long long) left[a[i] / k] * right[(long long) a[i] * k]; 
    }
    left[a[i]]++;
  }
  cout << ans << '\n';
  return 0;
}