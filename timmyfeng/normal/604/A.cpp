#include <bits/stdc++.h>
using namespace std;

int t[5 + 1], w[5 + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i <= 5; ++i) {
    cin >> t[i];
  }

  for (int i = 1; i <= 5; ++i) {
    cin >> w[i];
  }

  int s, u;
  cin >> s >> u;

  int ans = 100 * s - 50 * u;
  for (int i = 1; i <= 5; ++i) {
    ans += max(150 * i, 500 * i - 2 * i * t[i] - 50 * w[i]);
  }

  cout << ans << "\n";
}