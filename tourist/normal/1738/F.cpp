/**
 *    author:  tourist
 *    created: 30.09.2022 18:05:12       
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
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
      cin >> d[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return d[i] > d[j];
    });
    vector<int> color(n, -1);
    for (int i : order) {
      if (color[i] != -1) {
        continue;
      }
      vector<int> comp(1, i);
      int into = i;
      for (int t = 0; t < d[i]; t++) {
        cout << "? " << i + 1 << endl;
        int j;
        cin >> j;
        --j;
        if (color[j] == -1) {
          comp.push_back(j);
        } else {
          into = color[j];
          break;
        }
      }
      for (int v : comp) {
        color[v] = into;
      }
    }
    cout << "!";
    for (int i = 0; i < n; i++) {
      cout << " " << color[i] + 1;
    }
    cout << endl;
  }
  return 0;
}