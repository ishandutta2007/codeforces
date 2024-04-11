/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 17:04:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  int k;
  cin >> k;
  for (int i = 0; i < n; i++) {
    if (l[i] <= k && k <= r[i]) {
      cout << n - i;
    }
  }                                             
  return 0;
}