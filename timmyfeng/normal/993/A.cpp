#include <bits/stdc++.h>
using namespace std;

const int A = 100;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y;

  int mn_x = A;
  int mx_x = -A;
  int mn_y = A;
  int mx_y = -A;
  for (int i = 0; i < 4; ++i) {
    cin >> x >> y;
    mn_x = min(mn_x, x);
    mx_x = max(mx_x, x);
    mn_y = min(mn_y, y);
    mx_y = max(mx_y, y);
  }

  int center_x = 0;
  int center_y = 0;
  for (int i = 0; i < 4; ++i) {
    cin >> x >> y;
    center_x += x;
    center_y += y;
  }
  center_x /= 4;
  center_y /= 4;
  int radius = abs(center_x - x) + abs(center_y - y);

  for (int i = mn_x; i <= mx_x; ++i) {
    for (int j = mn_y; j <= mx_y; ++j) {
      if (abs(center_x - i) + abs(center_y - j) <= radius) {
        cout << "YES\n";
        exit(0);
      }
    }
  }
  cout << "NO\n";
}