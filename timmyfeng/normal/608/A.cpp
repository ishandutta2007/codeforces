#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;

  int ans = s;
  for (int i = 0; i < n; ++i) {
    int f, t;
    cin >> f >> t;
    ans = max(ans, f + t);
  }

  cout << ans << "\n";
}