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

    set<int> seen;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      seen.insert(a);
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      int b;
      cin >> b;
      if (seen.find(b) != seen.end()) {
        ans = b;
      }
    }

    if (ans == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << 1 << " " << ans << "\n";
    }
  }
}