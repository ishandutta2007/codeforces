/**
 *    author:  milos
 *    created: 10.08.2021 09:04:11       
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
    for (int i = 0; i < n; i++) {
      a.push_back(a[i]);
    }
    const int LOG = 25;
    vector<vector<int>> st(n * 2, vector<int>(LOG));
    for (int i = 0; i < 2 * n; i++) {
      st[i][0] = a[i];
    }
    for (int j = 1; j < LOG; j++) {
      for (int i = 0; i + (1 << j) <= 2 * n; i++) {
        st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
    vector<int> logs(2 * n + 1);
    for (int i = 2; i <= 2 * n; i++) {
      logs[i] = logs[i / 2] + 1;
    }
    auto Get = [&](int L, int R) {
      int sz = R - L + 1;
      int lg = logs[sz];
      return __gcd(st[L][lg], st[R - (1 << lg) + 1][lg]);  
    }; 
    int bot = 0, top = n, ans = n;
    while (bot <= top) {
      int mid = bot + top >> 1;
      vector<int> b;
      for (int i = 0; i < n; i++) {
        b.push_back(Get(i, i + mid));
      }
      if (*min_element(b.begin(), b.end()) == *max_element(b.begin(), b.end())) {
        ans = mid;
        top = mid - 1;
      } else {
        bot = mid + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}