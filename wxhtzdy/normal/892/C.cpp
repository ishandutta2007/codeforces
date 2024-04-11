#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      cnt++;
    }
  }
  if (cnt) {
    cout << n - cnt << '\n';
    return 0;
  }
  int ans = n + 1;
  for (int i = 0; i < n; i++) {
    int g = a[i];
    for (int j = i + 1; j < n; j++) {
      g = __gcd(g, a[j]);
      if (g == 1) {
        ans = min(ans, j - i + 1);
        break;
      }
    }
  }
  if (ans == n + 1) {
    cout << -1 << '\n';
    return 0;
  }
  cout << n + ans - 2 << '\n';
  return 0;
}