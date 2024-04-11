/**
 *    author:  wxhtzdy
 *    created: 18.06.2022 20:19:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vector<int> x(k);
  vector<int> y(k);
  for (int i = 0; i < k; i++) {
    cin >> x[i] >> y[i];
    --x[i]; --y[i];
  }     
  vector<int> xl(q);
  vector<int> yl(q);
  vector<int> xr(q);
  vector<int> yr(q);
  for (int i = 0; i < q; i++) {
    cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
    --xl[i]; --yl[i]; --xr[i]; --yr[i];
  }
  vector<int> ans(q);
  vector<int> st(4 * max(n, m));    
  function<void(int, int, int, int, int)> modify = [&](int node, int l, int r, int i, int v) {
    if (l == r) {
      st[node] = v;
      return;
    }
    int mid = l + r >> 1;
    if (i <= mid) {
      modify(node + node, l, mid, i, v);
    } else {
      modify(node + node + 1, mid + 1, r, i, v);
    }
    st[node] = min(st[node + node], st[node + node + 1]);
  };
  function<int(int, int, int, int, int)> get = [&](int node, int l, int r, int ll, int rr) {
    if (l > r || l > rr || r < ll) {
      return (int) 1e9;
    }
    if (ll <= l && r <= rr) {
      return st[node];
    }
    int mid = l + r >> 1;
    return min(get(node + node, l, mid, ll, rr), get(node + node + 1, mid + 1, r, ll, rr));
  };
  function<void()> Solve = [&]() {
    fill(st.begin(), st.end(), -1);
    vector<vector<pair<int, int>>> qs(n + 1);
    for (int i = 0; i < q; i++) {
      qs[xr[i]].emplace_back(i, 1);
    }
    for (int i = 0; i < k; i++) {
      qs[x[i]].emplace_back(y[i], 0);
    }
    for (int i = 0; i < n; i++) {
      for (auto &p : qs[i]) {
        if (p.second == 0) {
          modify(1, 0, m - 1, p.first, i);
        }
      }
      for (auto &p : qs[i]) {
        if (p.second == 1) {
          ans[p.first] |= (get(1, 0, m - 1, yl[p.first], yr[p.first]) >= xl[p.first] ? 1 : 0);
        }
      }
    }
  };
  Solve();
  for (int i = 0; i < k; i++) {
    swap(x[i], y[i]);
  }
  for (int i = 0; i < q; i++) {
    swap(xl[i], yl[i]);
    swap(xr[i], yr[i]);
  }
  swap(n, m);
  Solve();
  for (int i = 0; i < q; i++) {
    cout << (ans[i] == 1 ? "YES" : "NO") << '\n';
  }                                              
  return 0;
}