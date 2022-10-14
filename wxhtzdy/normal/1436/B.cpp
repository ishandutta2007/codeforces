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
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j || (j + 1) % n == i) {
          cout << 1 << " ";
        } else {
          cout << 0 << " ";
        }
      }
      cout << '\n';
    }
  }
  return 0;
}