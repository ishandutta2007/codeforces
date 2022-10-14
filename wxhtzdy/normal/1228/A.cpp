#include <bits/stdc++.h>

using namespace std;

bool Ok(int n) {
  vector<bool> was(10, false);
  while (n > 0) {
    if (was[n % 10]) {
      return false;
    }
    was[n % 10] = true;
    n /= 10;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, r;
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    if (Ok(i)) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}