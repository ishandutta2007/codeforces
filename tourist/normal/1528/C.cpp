/**
 *    author:  tourist
 *    created: 24.05.2021 17:44:34       
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
    for (int i = 1; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<int> b(n);
    for (int i = 1; i < n; i++) {
      cin >> b[i];
      --b[i];
    }
    vector<vector<int>> ga(n);
    vector<vector<int>> gb(n);
    for (int i = 1; i < n; i++) {
      ga[a[i]].push_back(i);
      gb[b[i]].push_back(i);
    }
    vector<int> order_b;
    vector<int> pos_b(n, -1);
    vector<int> end_b(n, -1);
    function<void(int)> DfsB = [&](int v) {
      pos_b[v] = (int) order_b.size();
      order_b.push_back(v);
      for (int u : gb[v]) {
        DfsB(u);
      }
      end_b[v] = (int) order_b.size() - 1;
    };
    DfsB(0);
    auto AncB = [&](int x, int y) {
      return (pos_b[x] <= pos_b[y] && end_b[y] <= end_b[x]);
    };
    int ans = 0;
    int cur = 0;
    set<int> s;
    auto Add = [&](int x) {
      x = pos_b[x];
      set<int>::iterator it = s.insert(x).first;
      int L = (it == s.begin() ? -1 : *prev(it));
      int R = (next(it) == s.end() ? -1 : *next(it));
      if (L != -1 && R != -1) {
        cur -= AncB(order_b[L], order_b[R]);
      }
      if (L != -1) {
        cur += AncB(order_b[L], order_b[x]);
      }
      if (R != -1) {
        cur += AncB(order_b[x], order_b[R]);
      }
      ans = max(ans, (int) s.size() - cur);
    };
    auto Remove = [&](int x) {
      x = pos_b[x];
      set<int>::iterator it = s.find(x);
      int L = (it == s.begin() ? -1 : *prev(it));
      int R = (next(it) == s.end() ? -1 : *next(it));
      if (L != -1 && R != -1) {
        cur += AncB(order_b[L], order_b[R]);
      }
      if (L != -1) {
        cur -= AncB(order_b[L], order_b[x]);
      }
      if (R != -1) {
        cur -= AncB(order_b[x], order_b[R]);
      }
      s.erase(it);
      ans = max(ans, (int) s.size() - cur);
    };
    function<void(int)> DfsA = [&](int v) {
      Add(v);
      for (int u : ga[v]) {
        DfsA(u);
      }
      Remove(v);
    };
    DfsA(0);
    cout << ans << '\n';
  }
  return 0;
}