#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int x = a, y = b;
  for (int i = 0; i < n; i++) {
    if (x == 0 && y == 0) {
      cout << i << '\n';
      return 0;
    }
    if (x == 0) {
      --y;
    } else {
      if (y == 0) {
        if (s[i] == 1 && y < b) {
          y++;
        }
        --x;
      } else {
        if (s[i] == 1 && y < b) {
          --x;
          y++;
        } else {
          --y;
        }
      }
    }
  }
  cout << n << '\n';
  return 0;
}