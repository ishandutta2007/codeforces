#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> occ(n, vector<int>(2));
  vector<vector<int>> prv(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      for (int x = 0; x < 2; x++) {
        occ[i][x] = occ[i - 1][x];
        prv[i][x] = prv[i - 1][x];
      }
    }
    if (s[i] != '?') {
      occ[i][s[i] - '0']++;
      prv[i][s[i] - '0'] = i;
    }
  }
  for (int x = 1; x <= n; x++) {
    int ptr = 0, ans = 0;
    while (ptr + x <= n) {
      int c0 = occ[ptr + x - 1][0] - (ptr == 0 ? 0 : occ[ptr - 1][0]);
      int c1 = occ[ptr + x - 1][1] - (ptr == 0 ? 0 : occ[ptr - 1][1]);
      if (c0 == 0 || c1 == 0) {
        ans++;
        ptr += x;
      } else {
        ptr = min(prv[ptr + x - 1][0], prv[ptr + x - 1][1]) + 1;
      }
    }
    cout << ans << " ";
  }
  return 0;
}