#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a0;
  cin >> n >> a0;

  int ans = 0;
  for (int i = 1, a1, b, c; i < n; ++i) {
    cin >> a1;
    tie(b, c) = minmax(a0, a1);
    while (2 * b < c)
      b *= 2, ++ans;
    a0 = a1;
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
    solve();
}