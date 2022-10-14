#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  int ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    ans++;
    if (sum >= m) {
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}