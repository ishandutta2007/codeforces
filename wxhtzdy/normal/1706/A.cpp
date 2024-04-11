/**
 *    author:  wxhtzdy
 *    created: 18.07.2022 18:06:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    sort(a.begin(), a.end());
    string s = string(m, 'B');
    for (int i = 0; i < n; i++) {
      if (a[i] < m - a[i] - 1) {
        if (s[a[i]] == 'B') {
          s[a[i]] = 'A';
        } else {
          s[m - a[i] - 1] = 'A';
        }
      } else {
        a[i] = m - a[i] - 1;
        if (s[a[i]] == 'B') {
          s[a[i]] = 'A';
        } else {
          s[m - a[i] - 1] = 'A';
        }
      }
    }
    cout << s << '\n';
  }                                                                    
  return 0;
}