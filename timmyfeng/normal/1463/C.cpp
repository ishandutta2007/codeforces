#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    int prv = 0, y = 0;
    int pos = 0, goal = 0;
    for (int i = 0; i < n; ++i) {
      int cur, x;
      cin >> cur >> x;
      if (goal > pos) {
        ans += (y >= pos && y <= min(pos + cur - prv, goal));
        pos = min(pos + cur - prv, goal);
      } else if (goal <= pos) {
        ans += (y >= max(pos - cur + prv, goal) && y <= pos);
        pos = max(pos - cur + prv, goal);
      }
      if (pos == goal) {
        goal = x;
      }
      prv = cur, y = x;
    }
    ans += (y >= min(pos, goal) && y <= max(pos, goal));
    cout << ans - 1 << "\n";
  }
}