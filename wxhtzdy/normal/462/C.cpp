/**
 *    author:  milos
 *    created: 31.07.2020 12:01:59      
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  long long ans = sum;
  for (int i = 0; i < n; i++) {
    ans += sum;
    sum -= a[i];
  }
  cout << ans - a[n - 1] << '\n';
  return 0;   
}