/**
 *    author:  tourist
 *    created: 29.12.2021 18:36:30       
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
    int k = 1;
    while (k < n && (s[k] < s[k - 1] || (k > 1 && s[k] == s[k - 1]))) {
      ++k;
    }
    for (int i = 0; i < k; i++) {
      cout << s[i];
    }
    for (int i = k - 1; i >= 0; i--) {
      cout << s[i];
    }
    cout << '\n';
  }
  return 0;
}