/**
 *    author:  tourist
 *    created: 27.09.2020 18:32:17       
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
    const int inf = (int) 1.01e9;
    long long L = 1;
    long long R = inf;
    set<long long> s;
    long long sign = 1;
    long long delta = 0;
    int ans = 0;
    for (int x : a) {
      if (x % 2 == 1) {
        swap(L, R);
        L = max(x - L, 1LL);
        R = min(x - R, x - 1LL);
        sign *= -1;
        delta *= -1;
        delta += x;
        while (!s.empty()) {
          long long val = (*s.begin()) * sign + delta;
          if (val < 1 || val >= x) {
            s.erase(s.begin());
          } else {
            break;
          }
        }
        while (!s.empty()) {
          auto it = prev(s.end());
          long long val = (*it) * sign + delta;
          if (val < 1 || val >= x) {
            s.erase(it);
          } else {
            break;
          }
        }
        if (s.empty() && L > R) {
          sign = 1;
          delta = 0;
          L = 1;
          R = x - 1;
        } else {
          ans += 1;
        }
      } else {
        swap(L, R);
        L = max(x - L, 1LL);
        R = min(x - R, x - 1LL);
        sign *= -1;
        delta *= -1;
        delta += x;
        if ((L <= x / 2 && x / 2 <= R) || s.find((x / 2 - delta) * sign) != s.end()) {
          ans += 2;
          s.clear();
          sign = 1;
          delta = 0;
          L = x / 2;
          R = x / 2;
        } else {
          while (!s.empty()) {
            long long val = (*s.begin()) * sign + delta;
            if (val < 1 || val >= x) {
              s.erase(s.begin());
            } else {
              break;
            }
          }
          while (!s.empty()) {
            auto it = prev(s.end());
            long long val = (*it) * sign + delta;
            if (val < 1 || val >= x) {
              s.erase(it);
            } else {
              break;
            }
          }
          s.insert((x / 2 - delta) * sign);
          ans += 1;
        }
      }
    }
    cout << 2 * n + 1 - ans << '\n';
  }
  return 0;
}