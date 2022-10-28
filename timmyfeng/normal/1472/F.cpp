#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    map<int, pair<bool, bool>> blocked;
    for (int i = 0; i < m; ++i) {
      int r, c;
      cin >> r >> c;
      if (r == 1) {
        blocked[c].first = true;
      } else {
        blocked[c].second = true;
      }
    }
    blocked[n + 1] = {true, true};

    bool top = true, bottom = true, ok = true;
    int prv = 0;

    for (auto [c, b] : blocked) {
      if (top == bottom) {
        top = bottom = false;
      } else if (prv % 2 != c % 2) {
        top ^= true, bottom ^= true;
      }

      if ((top && b.first) || (bottom && b.second)) {
        ok = false;
        break;
      }
      bottom |= b.second;
      top |= b.first;
      prv = c;
    }

    cout << (ok ? "YES" : "NO") << "\n";
  }
}