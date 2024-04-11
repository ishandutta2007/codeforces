/**
 *    author:  milos
 *    created: 28.08.2021 12:31:26       
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
  multiset<int> s;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (!s.empty() && *s.begin() < a[i]) {
      ans += a[i] - *s.begin();
      s.erase(s.begin());
      s.insert(a[i]);
      s.insert(a[i]);
    } else {
      s.insert(a[i]);
    }
  }
  cout << ans << '\n';
  return 0;
}