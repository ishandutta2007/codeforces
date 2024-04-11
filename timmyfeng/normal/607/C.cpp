#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s, t;
  cin >> n >> s >> t;

  for (auto &i : t) {
    if (i == 'N') {
      i = 'S';
    } else if (i == 'S') {
      i = 'N';
    } else if (i == 'E') {
      i = 'W';
    } else {
      i = 'E';
    }
  }

  reverse(t.begin(), t.end());
  t += s;
  --n;

  vector<int> z(2 * n);
  for (int i = 1, l = 0, r = 0; i < 2 * n; ++i) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    for ( ; i + z[i] < 2 * n && t[z[i]] == t[i + z[i]]; ++z[i]);
    if (i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1;
    }
  }

  bool ok = true;
  for (int i = 0; i < n; ++i) {
    ok &= (z[n + i] + i < n);
  }

  cout << (ok ? "YES" : "NO") << "\n";
}