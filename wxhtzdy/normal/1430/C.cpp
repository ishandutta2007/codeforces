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
    int j = n - 1;
    for (int i = n; i >= 1; i--) {
      if (i == (i + j + 1) / 2) {
          j = (i + j + 1) / 2;
          i--;
          continue;
      }
      j = (i + j + 1) / 2;
    }
    cout << j << '\n';
    j = n - 1;
    for (int i = n; i >= 1; i--) {
      cout << i << " " << j << '\n';
      if (i == (i + j + 1) / 2) {
          j = (i + j + 1) / 2;
          i--;
          continue;
      }
      j = (i + j + 1) / 2;
    }
  }
  return 0;
}