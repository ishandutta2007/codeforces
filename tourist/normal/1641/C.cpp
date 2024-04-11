/**
 *    author:  tourist
 *    created: 23.02.2022 13:39:11       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  vector<pair<int, int>> qs;
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(i);
  }
  for (int i = 0; i < tt; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      --x;
      qs.emplace_back(x, -1);
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      --l; --r;
      if (x == 0) {
        while (true) {
          auto it = s.lower_bound(l);
          if (it != s.end() && (*it) <= r) {
            qs.emplace_back(*it, -2);
            s.erase(it);
          } else {
            break;
          }
        }
      } else {
        qs.emplace_back(l, r);
      }
    }
  }
  tt = (int) qs.size();
  vector<int> low(tt);
  vector<int> high(tt);
  for (int i = 0; i < tt; i++) {
    if (qs[i].second >= 0) {
      low[i] = i;
      high[i] = tt;
    }
  }
  vector<int> mid(tt);
  while (true) {
    vector<vector<int>> at(tt + 1);
    bool any = false;
    for (int i = 0; i < tt; i++) {
      if (low[i] < high[i]) {
        mid[i] = (low[i] + high[i]) >> 1;
        at[mid[i]].push_back(i);
        any = true;
      }
    }
    if (!any) {
      break;
    }
    fenwick<int> fenw(n);
    for (int i = 0; i < tt; i++) {
      if (qs[i].second == -2) {
        fenw.modify(qs[i].first, +1);
      }
      for (int j : at[i]) {
        int sum = fenw.get(qs[j].second) - fenw.get(qs[j].first - 1);
        int len = qs[j].second - qs[j].first + 1;
        assert(sum < len);
        if (sum == len - 1) {
          high[j] = mid[j];
        } else {
          low[j] = mid[j] + 1;
        }
      }
    }
  }
  vector<vector<int>> at(tt + 1);
  for (int i = 0; i < tt; i++) {
    if (qs[i].second >= 0) {
      at[low[i]].push_back(i);
    }
  }
  fenwick<long long> fenw(n);
  for (int i = 0; i < n; i++) {
    fenw.modify(i, i);
  }
  vector<int> res(n, 0);
  for (int i = 0; i < tt; i++) {
    if (qs[i].second == -2) {
      fenw.modify(qs[i].first, -qs[i].first);
      res[qs[i].first] = -1;
    }
    if (qs[i].second == -1) {
      int x = res[qs[i].first];
      cout << (x == 0 ? "N/A" : (x == 1 ? "YES" : "NO")) << '\n';
    }
    if (qs[i].second >= 0) {
      // pass
    }
    for (int j : at[i]) {
      long long sum = fenw.get(qs[j].second) - fenw.get(qs[j].first - 1);
      assert(qs[j].first <= sum && sum <= qs[j].second);
      res[sum] = 1;
    }
  }
  return 0;
}