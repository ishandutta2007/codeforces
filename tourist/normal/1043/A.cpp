/**
 *    author:  tourist
 *    created: 28.10.2018 18:35:37       
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
  int k = *max_element(a.begin(), a.end());
  int diff = 0;
  for (int i = 0; i < n; i++) {
    diff -= k - a[i];
    diff += a[i];
  }
  if (diff >= 0) {
    k += diff / n + 1;
  }
  cout << k << '\n';
  return 0;
}