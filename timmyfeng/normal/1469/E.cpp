#include <bits/stdc++.h>
using namespace std;

const int N = 5000000;
const int L = 20;

int to[N][2], sub[N];

void dfs(int u) {
  for (int i = 0; i < 2; ++i) {
    if (to[u][i] != 0) {
      dfs(to[u][i]);
      sub[u] += sub[to[u][i]];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    to[0][0] = to[0][1] = sub[0] = 0;
    int m = 1;

    for (int i = 0, j = 0; i + k <= n; ++i) {
      for (j = max(i, j); j < n && s[j] == '1'; ++j);
      if (j - i >= k - L) {
        int u = 0;
        for (int l = i + max(0, k - L); l < i + k; ++l) {
          int c = s[l] - '0';
          if (to[u][c] == 0) {
            to[m][0] = to[m][1] = sub[m] = 0;
            to[u][c] = m++;
          }
          u = to[u][c];
        }
        sub[u] = 1;
      }
    }

    dfs(0);

    if (sub[0] >= (1 << min(k, L))) {
      cout << "NO\n";
      continue;
    }

    int u = 0;
    string ans;
    bool ok = false;

    for (int i = min(k, L) - 1; i >= 0; --i) {
      if (ok) {
        ans += '0';
        continue;
      }

      if (to[u][1] == 0 || sub[to[u][1]] < (1 << i)) {
        ans += '0';
        u = to[u][1];
      } else {
        ans += '1';
        u = to[u][0];
      }

      ok |= (u == 0);
    }

    cout << "YES\n";
    cout << string(max(0, k - L), '0') << ans << "\n";
  }
}