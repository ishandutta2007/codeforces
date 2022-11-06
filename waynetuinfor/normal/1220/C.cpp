#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int g = 256;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] <= g) cout << "Mike\n";
    else cout << "Ann\n";
    g = min(g, (int)s[i]);
  }
}