/**
 *    author:  milos
 *    created: 25.02.2021 09:53:39       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];  
  }
  vector<long long> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = a[i] - b[i];
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) {
    return c[i] > c[j];
  });
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += c[id[i]] * (i + 1) - a[id[i]] + b[id[i]] * n;   
  }
  cout << ans << '\n';
  return 0;
}