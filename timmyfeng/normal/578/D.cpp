#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;
const int A = 26;

long long ways_upper[N], ways_lower[N][A], ways_both[N][A], ways_none[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  string s;
  cin >> n >> m >> s;

  for (int i = 0; i < n; ++i) {
    ways_upper[i + 1] = ways_upper[i];
    for (int j = 0; j < m; ++j) {
      if (j + 'a' != s[i]) {
        ways_upper[i + 1] += ways_both[i][j];
      }
    }

    for (int j = 0; j < m; ++j) {
      ways_lower[i + 1][j] = ways_lower[i][s[i] - 'a'];
      if (i > 0 && j + 'a' != s[i - 1]) {
        ways_lower[i + 1][j] += ways_both[i][s[i] - 'a'];
      }
    }

    for (int j = 0; j < m; ++j) {
      if (j + 'a' != s[i]) {
        ++ways_both[i + 1][j];
        if (i > 0 && j + 'a' == s[i - 1]) {
          ways_both[i + 1][j] += ways_both[i][s[i] - 'a'];
        }
      }
    }

    ways_none[i + 1] = ways_none[i];
    if (i > 0 && s[i] != s[i - 1]) {
      ways_none[i + 1] += ways_upper[i];
    }
    for (int j = 0; j < m; ++j) {
      if (j + 'a' != s[i]) {
        ways_none[i + 1] += ways_lower[i][j];
        if (i > 0 && s[i] != s[i - 1]) {
          ways_none[i + 1] += ways_both[i][j];
        }
      }
    }
  }

  long long ans = ways_none[n] + ways_upper[n];
  for (int i = 0; i < m; ++i) {
    ans += ways_lower[n][i] + ways_both[n][i];
  }

  cout << ans << "\n";
}