/**
 *    author:  tourist
 *    created: 03.04.2020 17:24:19       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> l(m);
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    cin >> l[i];
    sum += l[i];
  }
  if (m > n) {
    cout << -1 << '\n';
    return 0;
  }
  if (sum < n) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 0; i < m; i++) {
    if (l[i] > n - i) {
      cout << -1 << '\n';
      return 0;
    }
  }
  vector<int> p(m + 1);
  p[m] = n;
  for (int i = m - 1; i >= 0; i--) {
    p[i] = max(i, p[i + 1] - l[i]);
  }
  for (int i = 0; i < m; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << p[i] + 1;
  }
  cout << '\n';
  return 0;
}