#include <bits/stdc++.h>
using namespace std;

const int N = 500000 + 1;

int prefix[N], suffix[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int n, a, b, t;
  cin >> n >> a >> b >> t >> s;

  if (s[0] == 'w') {
    t -= b;
  }

  if (--t < 0) {
    cout << 0 << "\n";
    exit(0);
  }

  for (int i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1] + 1 + a + (s[i] == 'w' ? b : 0);
  }

  for (int i = n - 1; i > 0; --i) {
    suffix[i] = suffix[i + 1] + 1 + a + (s[i] == 'w' ? b : 0);
  }

  int ans = 0;
  for (int i = n - 1, j = n; i >= 0; --i) {
    for ( ; j > i && prefix[i] + suffix[j] + i * a <= t; --j) {
      ans = max(ans, i + 1 + n - j);
    }
  }

  for (int i = 1, j = 0; i <= n; ++i) {
    for ( ; j < i && suffix[i] + prefix[j] + (n - i) * a <= t; ++j) {
      ans = max(ans, j + 1 + n - i);
    }
  }

  cout << ans << "\n";
}