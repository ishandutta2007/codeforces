#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  int bal = 0;
  int mn = 0;
  for (char c : s) {
    if (c == '(') {
      ++bal;
    } else {
      --bal;
    }
    mn = min(mn, bal);
  }
  cout << (bal == 0 && mn >= -1 ? "Yes" : "No") << "\n";
}