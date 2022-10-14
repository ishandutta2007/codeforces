/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 15:02:10
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
    double x;
    cin >> x;
    a[i] = floor(x);
    b[i] = ceil(x);                    
  }                                          
  long long s = 0;
  for (int i = 0; i < n; i++) {
    s += a[i];
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (abs(s) > abs(s - a[i] + b[i])) {
      s -= a[i];
      s += b[i];
      ans[i] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (ans[i] == 0 ? a[i] : b[i]) << '\n';
  }                              
  return 0;
}