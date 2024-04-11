/**
 *    author:  milos
 *    created: 25.09.2021 12:18:41       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  int sum = k * x;
  for (int i = 0; i < n - k; i++) {
    sum += a[i];
  }
  cout << sum << '\n';
  return 0;
}