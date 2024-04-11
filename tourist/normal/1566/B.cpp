/**
 *    author:  tourist
 *    created: 12.09.2021 17:36:50       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int k0 = 0;
    int k1 = 0;
    int first = -1;
    int last = -1;
    int n = (int) s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (first == -1) {
          first = i;
        }
        last = i;
        k0 += 1;
      } else {
        k1 += 1;
      }
    }
    if (k0 == 0) {
      cout << 0 << '\n';
      continue;
    }
    if (last - first + 1 == k0) {
      cout << 1 << '\n';
      continue;
    }
    cout << 2 << '\n';
  }
  return 0;
}