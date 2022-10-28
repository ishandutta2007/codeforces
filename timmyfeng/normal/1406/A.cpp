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
    set<int> a, b;
    for (int i = 0; i < n; ++i) {
      int c;
      cin >> c;
      if (a.count(c) == 1) {
        b.insert(c);
      } else {
        a.insert(c);
      }
    }

    int ans = 0;
    for (auto i : {a, b}) {
      int mex = 0;
      while (i.count(mex) == 1) {
        ++mex;
      }
      ans += mex;
    }
    cout << ans << "\n";
  }
}