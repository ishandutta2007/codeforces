#include <bits/stdc++.h>
using namespace std;

int query(int x) {
  if (x == 0) {
    return INT_MAX;
  }

  cout << "? " << x << endl;
  int y;
  cin >> y;
  return y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int l = 1, r = n;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (query(m - 1) > query(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  cout << "! " << l << endl;
}