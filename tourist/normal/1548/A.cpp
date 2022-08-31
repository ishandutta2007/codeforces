/**
 *    author:  tourist
 *    created: 01.08.2021 17:34:56       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> deg(n);
  int cnt = n;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if (x > y) swap(x, y);
    if (deg[x] == 0) cnt -= 1;
    deg[x] += 1;
  }
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      if (x > y) swap(x, y);
      if (deg[x] == 0) cnt -= 1;
      deg[x] += 1;
    }
    if (op == 2) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      if (x > y) swap(x, y);
      deg[x] -= 1;
      if (deg[x] == 0) cnt += 1;
    }
    if (op == 3) {
      cout << cnt << '\n';
    }
  }
  return 0;
}