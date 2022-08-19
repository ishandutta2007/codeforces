/**
 *    author:  tourist
 *    created: 24.11.2019 11:39:08       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<string> s(n + 1, string(n, '0'));
  int start = 0;
  for (int val = n; val >= 1; val--) {
    for (int i = 0; i < n; i++) {
      if (a[i] == val) {
        for (int j = 0; j < a[i]; j++) {
          s[(start + j) % (n + 1)][i] = '1';
        }
        start += 1;
      }
    }
  }
  cout << n + 1 << '\n';
  for (int i = 0; i < n + 1; i++) {
    cout << s[i] << '\n';
  }
  return 0;
}