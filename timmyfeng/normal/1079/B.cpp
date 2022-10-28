#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int r = (int(s.size()) - 1) / 20 + 1;
  int c = (int(s.size()) - 1) / r + 1;

  int cur = 0;
  cout << r << " " << c << "\n";
  for (int i = 0; i < r; ++i) {
    if (i >= int(s.size()) % r && int(s.size()) % r > 0) {
      cout << "*" << s.substr(cur, c - 1) << "\n";
      cur += c - 1;
    } else {
      cout << s.substr(cur, c) << "\n";
      cur += c;
    }
  }
}