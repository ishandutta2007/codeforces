#include <bits/stdc++.h>
using namespace std;

const int N = 200'000 + 1;

int prefix[N];
int suffix[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  for (int i = 0, j = 0; i < m; ++i) {
    while (s[j] != t[i]) {
      ++j;
    }
    prefix[i + 1] = ++j;
  }

  suffix[m] = n - 1;
  for (int i = m - 1, j = n - 1; i >= 0; --i) {
    while (s[j] != t[i]) {
      --j;
    }
    suffix[i] = --j;
  }

  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans = max(ans, suffix[i] - prefix[i] + 1);
  }

  cout << ans << "\n";
}