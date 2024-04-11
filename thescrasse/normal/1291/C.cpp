#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, h, a[3510], b[3510], res, x, r1;
deque<pair<long long, long long>> sm;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    while (!sm.empty()) {
      sm.pop_back();
    }
    cin >> n >> m >> h;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < m; i++) {
      b[i] = max(a[i], a[n - m + i]);
    }
    if (h >= m - 1) {
      res = 0;
      for (i = 0; i < m; i++) {
        res = max(res, b[i]);
      }
    } else {
      res = 0;
      x = m - h;
      for (i = 0; i < n; i++) {
        // cout << b[i] << ' ';
      }
      // cout << endl;
      for (i = 0; i < x; i++) {
        while (!sm.empty()) {
          if (sm.back().first >= b[i]) {
            sm.pop_back();
            // cout << "elemento tolto dalla fine" << endl;
          } else {
            break;
          }
        }
        sm.push_back({b[i], i});
        // cout << "inserito " << b[i] << endl;
      }
      res = max(res, sm.front().first);
      for (i = x; i < m; i++) {
        if (sm.front().second == i - x) {
          sm.pop_front();
          // cout << "elemento tolto dall'inizio" << endl;
        }
        while (!sm.empty()) {
          if (sm.back().first >= b[i]) {
            sm.pop_back();
            // cout << "elemento tolto dalla fine" << endl;
          } else {
            break;
          }
        }
        sm.push_back({b[i], i});
        // cout << "inserito " << b[i] << endl;
        res = max(res, sm.front().first);
      }
    }
    cout << res << endl;
  }

  return 0;
}