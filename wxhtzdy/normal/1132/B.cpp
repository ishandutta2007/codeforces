/**
 *  author: milos
 *  created: 15.12.2020 07:56:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << sum - a[n - x] << '\n';
  }                  
  return 0;
}