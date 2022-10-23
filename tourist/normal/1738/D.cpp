/**
 *    author:  tourist
 *    created: 30.09.2022 17:46:57       
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
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      --b[i];
    }
    vector<vector<int>> at(n + 2);
    for (int i = 0; i < n; i++) {
      at[b[i] + 1].push_back(i);
    }
    vector<int> color(n, -1);
    int flag = 0;
    vector<int> all = {-1, n};
    vector<int> perm;
    while (!all.empty()) {
      vector<int> nons;
      for (int x : all) {
        if (!at[x + 1].empty()) {
          nons.push_back(x);
        }
      }
      if (nons.empty()) {
        break;
      }
      assert(nons.size() == 1);
      if (nons[0] == -1) {
        flag = 1;
      }
      if (nons[0] == n) {
        flag = 0;
      }
      for (int i = (int) perm.size() - 1; i >= 0; i--) {
        if (perm[i] == nons[0]) {
          swap(perm[i], perm.back());
          break;
        }
      }
      all = at[nons[0] + 1];
      for (int x : all) {
        perm.push_back(x);
        color[x] = flag;
      }
      flag ^= 1;
    }
    assert((int) perm.size() == n);
    for (int i = 0; i <= n; i++) {
      if (i == n || color[i] == 1) {
        cout << i << '\n';
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << perm[i] + 1 << " \n"[i == n - 1];
    }
  }
  return 0;
}