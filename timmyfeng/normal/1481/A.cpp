#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int x, y;
    string s;
    cin >> x >> y >> s;

    int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
    for (auto c : s) {
      if (c == 'U') {
        ++max_y;
      } else if (c == 'D') {
        --min_y;
      } else if (c == 'R') {
        ++max_x;
      } else {
        --min_x;
      }
    }

    cout << (min_x <= x && x <= max_x && min_y <= y && y <= max_y ? "YES" : "NO") << "\n";
  }
}