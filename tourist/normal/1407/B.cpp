/**
 *    author:  tourist
 *    created: 09.09.2020 21:25:03       
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> c(1, 0);
    vector<int> b;
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
      int best = -1;
      int id = -1;
      for (int j = 0; j < n; j++) {
        if (!used[j] && __gcd(c.back(), a[j]) > best) {
          best = __gcd(c.back(), a[j]);
          id = j;
        }
      }
      used[id] = true;
      c.push_back(best);
      b.push_back(a[id]);
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << b[i];
    }
    cout << '\n';
  }
  return 0;
}