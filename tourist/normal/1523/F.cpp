/**
 *    author:  tourist
 *    created: 30.05.2021 18:50:34       
**/
#include <bits/stdc++.h>

using namespace std;

const __int128 one = 1;

const int inf = (int) 1.01e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> xa(n), ya(n);
  for (int i = 0; i < n; i++) {
    cin >> xa[i] >> ya[i];
  }
  vector<int> xb(m), yb(m), tb(m);
  for (int i = 0; i < m; i++) {
    cin >> xb[i] >> yb[i] >> tb[i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      if (tb[i] > tb[j]) {
        swap(xb[i], xb[j]);
        swap(yb[i], yb[j]);
        swap(tb[i], tb[j]);
      }
    }
  }
  vector<int> at_mask(1 << n, inf);
  for (int t = 0; t < (1 << n); t++) {
    if (__builtin_popcount(t) == 1) {
      at_mask[t] = 0;
    }
  }
  vector<vector<int>> mask_dist_a(1 << n, vector<int>(n));
  for (int t = 0; t < (1 << n); t++) {
    for (int i = 0; i < n; i++) {
      mask_dist_a[t][i] = inf;
      for (int j = 0; j < n; j++) {
        if (t & (1 << j)) {
          mask_dist_a[t][i] = min(mask_dist_a[t][i], abs(xa[i] - xa[j]) + abs(ya[i] - ya[j]));
        }
      }
    }
  }
  vector<vector<int>> mask_dist_b(1 << n, vector<int>(m));
  for (int t = 0; t < (1 << n); t++) {
    for (int i = 0; i < m; i++) {
      mask_dist_b[t][i] = inf;
      for (int j = 0; j < n; j++) {
        if (t & (1 << j)) {
          mask_dist_b[t][i] = min(mask_dist_b[t][i], abs(xb[i] - xa[j]) + abs(yb[i] - ya[j]));
        }
      }
    }
  }
  vector<__int128> go_qq(m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (i != j && tb[i] + abs(xb[i] - xb[j]) + abs(yb[i] - yb[j]) <= tb[j]) {
        go_qq[j] |= (one << i);
      }
    }
  }
  vector<vector<int>> val(n, vector<int>(m));
  vector<vector<int>> seq(n, vector<int>(m));
  vector<vector<__int128>> pref(n, vector<__int128>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      val[i][j] = tb[j] + abs(xb[j] - xa[i]) + abs(yb[j] - ya[i]);
      seq[i][j] = j;
    }
    sort(seq[i].begin(), seq[i].end(), [&](int x, int y) {
      return val[i][x] < val[i][y];
    });
    for (int j = 0; j < m; j++) {
      pref[i][j] = (one << seq[i][j]);
      if (j > 0) {
        pref[i][j] |= pref[i][j - 1];
      }
    }
  }
  vector<__int128> can(1 << n);
  for (int ans = 0; ; ans++) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
    for (int t = 0; t < (1 << n); t++) {
      if (at_mask[t] < inf) {
        s.emplace(at_mask[t], t);
      }
    }
    while (!s.empty()) {
      int expected = s.top().first;
      int t = s.top().second;
      s.pop();
      if (at_mask[t] != expected) {
        continue;
      }
      for (int i = 0; i < n; i++) {
        if (!(t & (1 << i))) {
          int to = t + (1 << i);
          int cost = at_mask[t] + mask_dist_a[t][i];
          if (cost < at_mask[to]) {
            at_mask[to] = cost;
            s.emplace(at_mask[to], to);
          }
        }
      }
    }
    vector<int> new_at_mask(1 << n, inf);
    vector<__int128> new_can(1 << n);
    bool any = false;
    for (int t = 0; t < (1 << n); t++) {
      for (int i = ans; i < m; i++) {
        if ((t == 0 && ans == 0) || (t > 0 && at_mask[t] + mask_dist_b[t][i] <= tb[i]) || (go_qq[i] & can[t])) {
          new_can[t] |= (one << i);
          new_at_mask[t] = min(new_at_mask[t], tb[i]);
        }
      }
      if (new_can[t]) {
        any = true;
        for (int j = 0; j < n; j++) {
          if (!(t & (1 << j))) {
            int low = 0;
            int high = m - 1;
            while (low < high) {
              int mid = (low + high) >> 1;
              if (pref[j][mid] & new_can[t]) {
                high = mid;
              } else {
                low = mid + 1;
              }
            }
            new_at_mask[t | (1 << j)] = min(new_at_mask[t | (1 << j)], val[j][seq[j][low]]);
          }
        }
      }
    }
    if (!any) {
      cout << ans << '\n';
      break;
    }
    swap(can, new_can);
    swap(at_mask, new_at_mask);
  }
  return 0;
}