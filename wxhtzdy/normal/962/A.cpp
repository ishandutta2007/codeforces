/**
 *    author:  milos
 *    created: 14.02.2021 20:00:30       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }         
  long long s = accumulate(a.begin(), a.end(), 0);
  long long t = 0;
  for (int i = 0; i < n; i++) {
    t += a[i];
    if (t >= (s + 1) / 2) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  return 0;
}