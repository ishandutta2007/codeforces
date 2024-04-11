/**
 *    author:  milos
 *    created: 26.01.2021 22:47:53       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  long long s = 0, t = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  sort(a.begin(), a.end());
  int j = 0;
  for (int i = 0; i < n; i++) {
    t += 1;
    if (a[i] > j) {
      j += 1;
    }
  }
  t = t + a[n - 1] - j;   
  cout << s - t << '\n';
  return 0;
}