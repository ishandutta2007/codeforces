/**
 *    author:  tourist
 *    created: 20.04.2019 21:08:01       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int bit = 0; bit < 9; bit++) {
      vector<int> a;
      vector<int> b;
      for (int i = 0; i < n; i++) {
        if ((i >> bit) & 1) {
          a.push_back(i);
        } else {
          b.push_back(i);
        }
      }
      if (a.empty() || b.empty()) {
        continue;
      }
      cout << (int) a.size() << " " << (int) b.size();
      for (int x : a) {
        cout << " " << x + 1;
      }
      for (int x : b) {
        cout << " " << x + 1;
      }
      cout << endl;
      int foo;
      cin >> foo;
      ans = max(ans, foo);
    }
    cout << -1 << " " << ans << endl;
  }
  return 0;
}