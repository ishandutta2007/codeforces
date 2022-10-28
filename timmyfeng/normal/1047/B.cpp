#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    ans = max(ans, u + v);
  }
  cout << ans << "\n";
}