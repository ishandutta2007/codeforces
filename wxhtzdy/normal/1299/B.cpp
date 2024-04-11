/**
 *    author:  wxhtzdy
 *    created: 06.02.2022 20:50:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  if (n % 2 == 1) {
    cout << "NO" << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int x1 = x[i];
    int y1 = y[i];
    int x2 = x[(i + 1) % n];
    int y2 = y[(i + 1) % n];
    int x3 = x[(i + n / 2 + 1) % n];
    int y3 = y[(i + n / 2 + 1) % n];
    int x4 = x[(i + n / 2) % n];
    int y4 = y[(i + n / 2) % n];
    int dx1 = x2 - x1;
    int dx2 = x4 - x3;
    int dy1 = y2 - y1;
    int dy2 = y4 - y3;
    if (dx1 != dx2 || dy1 != dy2) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  return 0;
}