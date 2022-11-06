#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') sum++;
    else sum--;
  }
  if (sum != 0) {
    cout << "No\n";
    return 0;
  }
  int bal = 0, v = n + 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') bal++;
    else bal--;
    v = min(v, bal);
  }
  if (v == -1 || v == 0) cout << "Yes\n";
  else cout << "No\n";
}