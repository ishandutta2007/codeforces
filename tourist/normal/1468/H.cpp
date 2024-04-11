/**
 *    author:  tourist
 *    created: 25.12.2020 15:29:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> k >> m;
    vector<bool> keep(n, false);
    for (int i = 0; i < m; i++) {
      int b;
      cin >> b;
      --b;
      keep[b] = true;
    }
    int half = k / 2;
    int rm = n - m;
    if (rm % (2 * half) != 0) {
      cout << "NO" << '\n';
      continue;
    }
    int steps = rm / (2 * half);
    int cnt = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (!keep[i]) {
        cnt += 1;
      } else {
        if (cnt >= half && rm - cnt >= half) {
          ok = true;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}