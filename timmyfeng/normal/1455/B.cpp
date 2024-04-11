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

    int ans = 0, y = 0;
    while (y < n) {
      y += ++ans;
    }

    if (y - n == 1) {
      ++ans;
    }
    cout << ans << "\n";
  }
}