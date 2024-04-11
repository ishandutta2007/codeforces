/**
 *    author:  tourist
 *    created: 27.12.2021 17:44:45       
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
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int ans = -1;
    vector<int> best(m, -1);
    for (int t = 0; t < (1 << n); t++) {
      vector<int> c(m);
      int cur = 0;
      for (int i = 0; i < n; i++) {
        int sign = (t & (1 << i)) ? 1 : -1;
        cur -= x[i] * sign;
        for (int j = 0; j < m; j++) {
          if (s[i][j] == '1') {
            c[j] += sign;
          }
        }
      }
      vector<int> order(m);
      iota(order.begin(), order.end(), 0);
      sort(order.begin(), order.end(), [&](int i, int j) {
        return c[i] < c[j];
      });
      for (int i = 0; i < m; i++) {
        cur += c[order[i]] * (i + 1);
      }
      if (cur > ans) {
        ans = cur;
        best = order;
      }
    }
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
      p[best[i]] = i + 1;
    }
    for (int i = 0; i < m; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << p[i];
    }
    cout << '\n';
  }
  return 0;
}