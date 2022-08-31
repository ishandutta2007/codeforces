/**
 *    author:  tourist
 *    created: 28.02.2021 16:34:56       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int pos;
      cin >> pos;
      --pos;
      s -= a[pos];
      a[pos] ^= 1;
      s += a[pos];
    } else {
      int k;
      cin >> k;
      cout << (k <= s ? 1 : 0) << '\n';
    }
  }
  return 0;
}