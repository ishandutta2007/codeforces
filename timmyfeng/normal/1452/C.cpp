#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    int ans = 0;
    int curve = 0;
    int square = 0;
    for (auto i : s) {
      if (i == '[') {
        ++square;
      } else if (i == ']') {
        if (square > 0) {
          --square;
          ++ans;
        }
      } else if (i == '(') {
        ++curve;
      } else {
        if (curve > 0) {
          --curve;
          ++ans;
        }
      }
    }
    cout << ans << "\n";
  }
}