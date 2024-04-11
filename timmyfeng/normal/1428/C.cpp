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
    for (auto i : s) {
      if (i == 'B' && ans != 0) {
        --ans;
      } else {
        ++ans;
      }
    }

    cout << ans << "\n";
  }
}