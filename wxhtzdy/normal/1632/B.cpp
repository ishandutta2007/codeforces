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
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 30; j++) {
        if ((i >> j) & 1) {
          b[i] = j + 1;
        }
      }
    }
    for (int i = 0; i + 1 < n; i++) {
      if (b[i + 1] == b[n - 1]) {
        swap(p[i], p[0]);
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << p[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}