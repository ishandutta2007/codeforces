#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  int cnt = 0;
  for (auto i : mp) {
    if (i.second > 0) cnt++;
  }
  if (cnt == 1) {
    cout << "0\n";
    return;
  }
  int x = a[n - 1];
  int ans = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > x) {
      x = a[i];
      ans++;
    }
  }
  cout << ans - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}