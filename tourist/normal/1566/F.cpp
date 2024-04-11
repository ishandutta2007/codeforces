/**
 *    author:  tourist
 *    created: 12.09.2021 18:00:05       
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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<pair<long long, long long>>> s(n + 1);
    for (int i = 0; i < m; i++) {
      long long x, y;
      cin >> x >> y;
      auto it = lower_bound(a.begin(), a.end(), x);
      if (it == a.end()) {
        s[n].emplace_back(x, y);
        continue;
      }
      int id = (int) (it - a.begin());
      if (x <= a[id] && y >= a[id]) {
        continue;
      }
      s[id].emplace_back(x, y);
    }
    long long dist = 0;
    for (auto& p : s[0]) {
      dist = max(dist, a[0] - p.second);
    }
    long long dp1 = dist;
    long long dp2 = dist * 2;
    vector<long long> pref;
    vector<long long> suf;
    for (int i = 1; i < n; i++) {
      sort(s[i].begin(), s[i].end());
      int sz = (int) s[i].size();
      suf.resize(sz + 1);
      suf[sz] = 0;
      for (int j = sz - 1; j >= 0; j--) {
        suf[j] = max(suf[j + 1], a[i] - s[i][j].second);
      }
      pref.resize(sz + 1);
      pref[0] = 0;
      for (int j = 0; j < sz; j++) {
        pref[j + 1] = max(pref[j], s[i][j].first - a[i - 1]);
      }
      long long new_dp1 = (long long) 4e18;
      long long new_dp2 = (long long) 4e18;
      for (int j = 0; j <= sz; j++) {
        long long x = pref[j];
        long long y = suf[j];
        new_dp1 = min(new_dp1, dp2 + x * 1 + y * 1);
        new_dp1 = min(new_dp1, dp1 + x * 2 + y * 1);
        new_dp2 = min(new_dp2, dp2 + x * 1 + y * 2);
        new_dp2 = min(new_dp2, dp1 + x * 2 + y * 2);
      }
      dp1 = new_dp1;
      dp2 = new_dp2;
    }
    dist = 0;
    for (auto& p : s[n]) {
      dist = max(dist, p.first - a[n - 1]);
    }
    long long ans = min(dp1 + dist * 2, dp2 + dist * 1);
    cout << ans << '\n';
  }
  return 0;
}