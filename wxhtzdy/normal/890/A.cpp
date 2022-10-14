#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a(6);
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < (1 << 6); i++) {
    int x = 0, y = 0, xx = 0, yy = 0;
    for (int j = 0; j < 6; j++) {
      if (i & (1 << j)) {
        x += a[j];
        xx++;
      } else {
        y += a[j];
        yy++;
      }
    }
    if (x == y && xx == yy) {
      cout << "YES" << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
  return 0;
}