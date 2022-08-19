/**
 *    author:  tourist
 *    created: 03.04.2021 17:34:27       
**/
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
    string s;
    cin >> s;
    if (s[0] == '0' || s[n - 1] == '0') {
      cout << "NO" << '\n';
      continue;
    }
    vector<int> eq, neq;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        eq.push_back(i);
      } else {
        neq.push_back(i);
      }
    }
    if (neq.size() % 2 == 1) {
      cout << "NO" << '\n';
      continue;
    }
    string a(n, ' ');
    string b(n, ' ');
    for (int i = 0; i < (int) eq.size(); i++) {
      if (i < (int) eq.size() / 2) {
        a[eq[i]] = b[eq[i]] = '(';
      } else {
        a[eq[i]] = b[eq[i]] = ')';
      }
    }
    for (int i = 0; i < (int) neq.size(); i += 2) {
      a[neq[i]] = b[neq[i + 1]] = '(';
      a[neq[i + 1]] = b[neq[i]] = ')';
    }
    cout << "YES" << '\n';
    cout << a << '\n';
    cout << b << '\n';
  }
  return 0;
}