#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i <= 30; i++) {
      if (n >> i & 1) {
        a.push_back(i);
      }
    }
    int y = (1 << a[0]);
    if ((n ^ y) != 0) {
      cout << y << '\n';
      continue;
    }
    for (int i = 0; i <= 30; i++) {
      if (!(n >> i & 1)) {
        y += (1 << i);
        break;
      }
    }
    cout << y << '\n';
  }
  return 0;
}