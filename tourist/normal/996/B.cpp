/**
 *    author:  tourist
 *    created: 24.11.2020 20:56:30       
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
  int j = 0;
  for (int i = 0; ; i++) {
    if (a[j] <= i) {
      cout << j + 1 << '\n';
      break;
    }
    j += 1;
    if (j >= n) {
      j = 0;
    }
  }
  return 0;
}