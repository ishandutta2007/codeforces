#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }

  int ans = 1e9;
  for (int i = 0; i < n; ++i) {
    int res = 0;
    for (int j = 0; j < n; ++j) {
      res += 2 * a[j] * (j + abs(j - i) + i);
    }
    ans = min(ans, res);
  }
  cout << ans << "\n";
}