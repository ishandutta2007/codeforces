#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  map<int, int> freq, ffreq;
  for (int i = 0, a; i < n; ++i)
    cin >> a, ++ffreq[++freq[a]];

  int ans = n;
  for (auto [u, v] : ffreq)
    ans = min(ans, n - u * v);

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