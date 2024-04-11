#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    bool ok = false;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ok |= a[i] == k;
    }
    if (!ok) {
      cout << "no\n";
      continue;
    }
    if (n == 1) {
      cout << "yes\n";
      continue;
    }
    bool res = false;
    int cnt = 0;
    vector<int> s(n + 1);
    for (int i = 0; i < n; ++i) {
      if (a[i] >= k) s[i + 1] = 1;
    }
    for (int i = 1; i <= n; ++i) s[i] += s[i - 1];
    int g = 1E9;
    for (int i = 1; i <= n; ++i) {
      if (2 * s[i] - i > g) {
        res = true;
      }
      g = min(g, 2 * s[i - 1] - (i - 1));
    }
    if (res) cout << "yes\n";
    else cout << "no\n";
  }
  return 0;
}