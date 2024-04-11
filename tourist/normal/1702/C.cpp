/**
 *    author:  tourist
 *    created: 10.07.2022 18:37:36       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> u(n);
    for (int i = 0; i < n; i++) {
      cin >> u[i];
    }
    map<int, int> first;
    map<int, int> last;
    for (int i = 0; i < n; i++) {
      if (first.find(u[i]) == first.end()) {
        first[u[i]] = i;
      }
      last[u[i]] = i;
    }
    while (k--) {
      int x, y;
      cin >> x >> y;
      if (first.find(x) == first.end() || last.find(y) == last.end()) {
        cout << "NO" << '\n';
        continue;
      }
      x = first[x];
      y = last[y];
      cout << (x <= y ? "YES" : "NO") << '\n';
    }
  }
  return 0;
}