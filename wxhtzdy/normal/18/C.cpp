#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int s = 0, t = accumulate(a.begin(), a.end(), 0), ans = 0;
  for (int i = 0; i < n - 1; i++) {
    s += a[i];
    t -= a[i];
    if (s == t) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}