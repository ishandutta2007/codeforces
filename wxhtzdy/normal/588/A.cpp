#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int mn = 1e9, ans = 0;
  for (int i = 0; i < n; i++) {
    int a, p;
    cin >> a >> p;
    mn = min(mn, p);
    ans += mn * a;
  }
  cout << ans << '\n';
  return 0;
}