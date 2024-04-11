/**
 *    author:  tourist
 *    created: 22.07.2021 17:48:53       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
    }
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
      int diff = (i - p[i] + n) % n;
      cnt[diff] += 1;
    }
    vector<int> res;
    for (int k = 0; k < n; k++) {
      if (cnt[k] >= n / 10) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
          a[i] = (i - k + n) % n;
        }
        vector<int> perm(n);
        for (int i = 0; i < n; i++) {
          perm[a[i]] = p[i];
        }
        vector<bool> was(n, false);
        int cnt = n;
        for (int i = 0; i < n; i++) {
          if (was[i]) {
            continue;
          }
          int x = i;
          while (!was[x]) {
            was[x] = true;
            x = perm[x];
          }
          cnt -= 1;
        }
        if (cnt <= m) {
          res.push_back(k);
        }
      }
    }
    cout << res.size();
    for (int x : res) {
      cout << " " << x;
    }
    cout << '\n';
  }
  return 0;
}