/**
 *  author: milos
 *  created: 06.01.2021 17:28:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  double sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if ((double) (sum / (double) n) >= 4.5) {
      cout << i << '\n';
      return 0;
    }
    sum -= a[i];
    sum += 5;
  }
  cout << n << '\n';
  return 0;
}