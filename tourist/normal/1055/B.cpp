/**
 *    author:  tourist
 *    created: 10.11.2018 17:42:00       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, l;
  cin >> n >> m >> l;
  vector<long long> tmp(n), a(n);
  for (int i = 0; i < n; i++) {
    cin >> tmp[i];
  }
  int ans = 0;
  auto add = [&](int x) {
    if (x == 0 || a[x - 1] <= l) {
      ans++;
    }
    if (x < n - 1 && a[x + 1] > l) {
      ans--;
    }
  };
  for (int i = 0; i < n; i++) {
    if (tmp[i] > l) {
      add(i);
    }
    a[i] = tmp[i];
  }
  while (m--) {
    int op;
    cin >> op;
    if (op == 0) {
      cout << ans << '\n';
    } else {
      int x, y;
      cin >> x >> y;
      x--;
      if (a[x] <= l && a[x] + y > l) {
        add(x);
      }
      a[x] += y;
    }
  }
  return 0;
}