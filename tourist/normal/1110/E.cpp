/**
 *    author:  tourist
 *    created: 07.02.2019 16:53:41       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> x, y;
  for (int i = 0; i < n - 1; i++) {
    x.push_back(a[i + 1] - a[i]);
    y.push_back(b[i + 1] - b[i]);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  if (a[0] != b[0] || a[n - 1] != b[n - 1] || x != y) {
    cout << "No" << '\n';
    return 0;
  }
  cout << "Yes" << '\n';
  return 0;
}