#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  while (m--) {
    int l, r;
    cin >> l >> r;
    --l; --r;
    char c1, c2;
    cin >> c1 >> c2;
    for (int i = l; i <= r; i++) {
      if (s[i] == c1) {
        s[i] = c2;
      }
    }
  }
  cout << s;
  return 0;
}