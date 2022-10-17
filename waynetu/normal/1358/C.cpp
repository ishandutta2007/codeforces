#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int64_t ans = 1LL * (c - a) * (d - b) + 1;
    cout << ans << "\n";
  }
}