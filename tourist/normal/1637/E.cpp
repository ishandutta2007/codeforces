/**
 *    author:  tourist
 *    created: 12.02.2022 17:51:14       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

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
    }
    vector<pair<int, int>> bad(m);
    for (int i = 0; i < m; i++) {
      cin >> bad[i].first >> bad[i].second;
    }
    sort(bad.begin(), bad.end());
    map<int, int> mp;
    for (int x : a) {
      mp[x] += 1;
    }
    map<int, vector<int>> mp2;
    for (auto& p : mp) {
      mp2[p.second].push_back(p.first);
    }
    vector<pair<int, vector<int>>> data(mp2.begin(), mp2.end());
    for (auto& p : data) {
      sort(p.second.rbegin(), p.second.rend());
    }
    int cnt = (int) data.size();
    set<tuple<long long, int, int, int, int>> s;
    auto Put = [&](int i, int pi, int j, int pj) {
      if (pi >= (int) data[i].second.size() || pj >= (int) data[j].second.size()) {
        return;
      }
      if (i == j && pi >= pj) {
        return;
      }
      s.emplace((long long) (data[i].first + data[j].first) * (data[i].second[pi] + data[j].second[pj]), i, pi, j, pj);
    };
    for (int i = 0; i < cnt; i++) {
      for (int j = i + 1; j < cnt; j++) {
        Put(i, 0, j, 0);
      }
    }
    for (int i = 0; i < cnt; i++) {
      if (data[i].second.size() >= 2) {
        Put(i, 0, i, 1);
      }
    }
    while (!s.empty()) {
      auto it = prev(s.end());
      auto tup = *it;
      int x = data[get<1>(tup)].second[get<2>(tup)];
      int y = data[get<3>(tup)].second[get<4>(tup)];
      if (x > y) {
        swap(x, y);
      }
      auto it2 = lower_bound(bad.begin(), bad.end(), make_pair(x, y));
      if (it2 == bad.end() || (*it2) != make_pair(x, y)) {
        cout << get<0>(tup) << '\n';
        break;
      }
      s.erase(it);
      Put(get<1>(tup), get<2>(tup) + 1, get<3>(tup), get<4>(tup));
      Put(get<1>(tup), get<2>(tup), get<3>(tup), get<4>(tup) + 1);
    }
  }
  return 0;
}