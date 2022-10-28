#include <bits/stdc++.h>
using namespace std;

int c[3];

void solve() {
  int n;
  cin >> n;

  fill(c, c + 3, 0);
  for (int i = 0, a; i < n; ++i)
    cin >> a, ++c[a % 3];

  int ans = 0;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      if (c[j] > n / 3) {
        int k = c[j] - n / 3;
        ans += k;
        c[(j + 1) % 3] += k;
        c[j] -= k;
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