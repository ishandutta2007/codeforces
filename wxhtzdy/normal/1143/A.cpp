#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> x, y;
  x.push_back(0);
  y.push_back(0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      x.push_back(i + 1);
    } else {
      y.push_back(i + 1);
    }
  }
  cout << min(x.back(), y.back()) << '\n';
  return 0;
}