#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  map<int, int> pos;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i] - 1] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    c[pos[b[i] - 1]] = i;
  }
  int ans = 0, k = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] < k) ans++;
    k = max(k, c[i]);
  }
  cout << ans << '\n';
  return 0;
}