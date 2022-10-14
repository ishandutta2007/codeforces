#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 0; i < n; i++) {
    a[i + 1] = (int) (s[i] - 'a');
    b[i + 1] = (int) (t[i] - 'a');
  }
  const int base = 26;
  for (int i = n; i >= 0; i--) {
    a[i] += b[i];
    if (i > 0) {
      a[i - 1] += a[i] / base;
      a[i] %= base;
    }
  }
  for (int i = 0; i <= n; i++) {
    if (i <= n - 1) {
      a[i + 1] += (a[i] % 2) * base;
    }
    a[i] /= 2;
  }
  string ans = "";
  for (int i = 1; i <= n; i++) {
    ans += (char) (a[i] + 'a');
  }
  cout << ans << '\n';
  return 0;
}