/**
 *    author:  tourist
 *    created: 06.04.2019 12:37:09       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, h;
  cin >> n >> h;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int k = n; k >= 0; k--) {
    vector<int> b(a.begin(), a.begin() + k);
    sort(b.begin(), b.end());
    long long sum = 0;
    for (int i = (int) b.size() - 1; i >= 0; i -= 2) {
      sum += b[i];
    }
    if (sum <= h) {
      cout << k << '\n';
      return 0;
    }
  }
  return 0;
}