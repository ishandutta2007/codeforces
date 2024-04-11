/**
 *    author:  tourist
 *    created: 19.12.2020 13:21:54       
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
    int n = (int) s.size();
    int pos = n;
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        a[pos] += 1;
        pos += 1;
      } else {
        pos -= 1;
        a[pos] += 1;
      }
    }
    int L = -1;
    int R = -1;
    for (int i = 0; i < 2 * n; i++) {
      if (a[i] != 0) {
        if (L == -1) L = i;
        R = i;
      }
    }
    int me = n;
    for (int i = 0; i < n; i++) {
      if (a[me - 1] > 0 && !(a[me - 1] == 1 && me - 1 < R)) {
        a[me - 1] -= 1;
        me -= 1;
        cout << 0;
      } else {
        assert(a[me] > 0);
        a[me] -= 1;
        me += 1;
        cout << 1;
      }
      while (L < R && a[L] == 0) {
        ++L;
      }
      while (L < R && a[R] == 0) {
        --R;
      }
    }
    cout << '\n';
  }
  return 0;
}