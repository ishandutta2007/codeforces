#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  string s, t;
  cin >> s >> t;
  int n;
  cin >> n;
  cout << s << " " << t << '\n';
  for (int i = 0; i < n; i++) {
    string x, y;
    cin >> x >> y;
    if (s == x) {
      s = y;
    } else if (s == y) {
      s = x;
    }
    if (t == x) {
      t = y;
    } else if (t == y) {
      t = x;
    }
    cout << s << " " << t << '\n';
  }
  return 0;
}