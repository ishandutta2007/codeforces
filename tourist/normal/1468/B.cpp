/**
 *    author:  tourist
 *    created: 25.12.2020 17:24:45       
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> s(n + 1);
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
  }
  vector<vector<int>> st(2 * n - 1);
  vector<vector<long long>> sx(2 * n - 1);
  function<void(int, int, int)> Build = [&](int x, int l, int r) {
    if (l < r) {
      int y = (l + r) >> 1;
      int z = x + 2 * (y - l + 1);
      Build(x + 1, l, y);
      Build(z, y + 1, r);
    }
    for (int i = l; i <= r; i++) {
      while (st[x].size() >= 2) {
        int j = st[x].back();
        long long inter = (s[i] - s[j]) / (i - j);
        if (inter <= sx[x].back()) {
          st[x].pop_back();
          sx[x].pop_back();
        } else {
          break;
        }
      }
      if (st[x].size() >= 1) {
        int j = st[x].back();
        long long inter = (s[i] - s[j]) / (i - j);
        sx[x].push_back(inter);
      }
      st[x].push_back(i);
    }
  };
  Build(0, 0, n - 1);
  vector<int> ids;
  function<void(int, int, int, int, int)> Go = [&](int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      ids.push_back(x);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + 2 * (y - l + 1);
    if (ll <= y) {
      Go(x + 1, l, y, ll, rr);
    }
    if (rr > y) {
      Go(z, y + 1, r, ll, rr);
    }
  };
  auto Ask = [&](int l, int r) {
    ids.clear();
    Go(0, 0, n - 1, l, r);
  };
  auto RealAsk = [&](long long k) {
    auto res = make_pair((long long) 1e18, -1);
    for (int x : ids) {
      int it = (int) (lower_bound(sx[x].begin(), sx[x].end(), k) - sx[x].begin());
      int who = st[x][it];
      res = min(res, make_pair(s[who] - k * who, who));
    }
    return res;
  };
  vector<pair<int, int>> report;
  function<void(int, int)> Solve = [&](int l, int r) {
    if (r == l + 1) {
      return;
    }
    Ask(l + 1, r - 1);
    int low = 0;
    int high = (int) 1.01e9;
    while (low < high) {
      int mid = (low + high) >> 1;
      auto p = RealAsk(mid);
      if (p.first <= s[l] - (long long) mid * l) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    report.emplace_back(low - 1, r - l - 1);
    auto p = RealAsk(low);
    Solve(l, p.second);
    Solve(p.second, r);
  };
  Solve(0, n);
  sort(report.begin(), report.end());
  int cnt = (int) report.size();
  vector<int> suf(cnt + 1);
  for (int i = cnt - 1; i >= 0; i--) {
    suf[i] = max(suf[i + 1], report[i].second);
  }
  int ptr = 0;
  while (m--) {
    int k;
    cin >> k;
    while (ptr < cnt && k > report[ptr].first) {
      ++ptr;
    }
    cout << suf[ptr] << '\n';
  }
  cerr << clock() << " ms" << '\n';
  return 0;
}