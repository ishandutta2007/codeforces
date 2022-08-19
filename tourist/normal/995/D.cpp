/**
 *    author:  tourist
 *    created: 24.11.2020 20:31:18       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  vector<int> a(1 << n);
  long long sum = 0;
  for (int i = 0; i < (1 << n); i++) {
    cin >> a[i];
    sum += a[i];
  }
  cout << fixed << setprecision(17) << (double) sum / (1 << n) << '\n';
  while (r--) {
    int x, y;
    cin >> x >> y;
    sum += y - a[x];
    a[x] = y;
    cout << fixed << setprecision(17) << (double) sum / (1 << n) << '\n';
  }
  return 0;
}