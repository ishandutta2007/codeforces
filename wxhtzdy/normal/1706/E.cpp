/**
 *    author:  wxhtzdy
 *    created: 18.07.2022 16:37:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> u(m), v(m);
    for (int i = 0; i < m; i++) {
      cin >> u[i] >> v[i];
      --u[i]; --v[i];
    }
    vector<int> ans(n);
    vector<int> low(n, 0);
    vector<int> high(n, m - 1);
    vector<vector<int>> qs(m);
    vector<int> p(n), sz(n);
    function<void()> Build = [&]() {
      for (int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
      }
      for (int i = 0; i < m; i++) {
        qs[i].clear();
      }
    };
    function<int(int)> get = [&](int x) {
      return p[x] == x ? x : p[x] = get(p[x]); 
    };
    function<void(int, int)> Merge = [&](int u, int v) {
      u = get(u);
      v = get(v);
      if (u == v) {
        return;
      }
      if (sz[u] > sz[v]) {
        swap(u, v);  
      }
      p[u] = v;
      sz[v] += sz[u];
    };
    for (int it = 0; it < 20; it++) {
      Build();
      for (int i = 0; i < n - 1; i++) {
        if (low[i] <= high[i]) {
          qs[(low[i] + high[i]) / 2].push_back(i);
        }
      }
      for (int i = 0; i < m; i++) {
        Merge(u[i], v[i]);
        for (int j : qs[i]) {
          if (get(j) == get(j + 1)) {
            ans[j] = i;
            high[j] = i - 1;
          } else {
            low[j] = i + 1;
          }
        }
      }
    }
    vector<int> mx(4 * n);
    function<void(int, int, int)> build = [&](int v, int l, int r) {
      if (l == r) {
        mx[v] = ans[l];
        return;
      }
      int mid = l + r >> 1;
      build(v * 2, l, mid);
      build(v * 2 + 1, mid + 1, r);
      mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
    };
    function<int(int, int, int, int, int)> query = [&](int v, int l, int r, int ll, int rr) {
      if (l > r || l > rr || r < ll) {
        return 0;
      }
      if (ll <= l && r <= rr) {
        return mx[v];
      }
      int mid = l + r >> 1;
      return max(query(v * 2, l, mid, ll, rr), query(v * 2 + 1, mid + 1, r, ll, rr));
    };
    build(1, 0, n - 2);
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      --l; --r;
      if (l == r) {
        cout << 0 << " ";
      } else {
        cout << query(1, 0, n - 2, l, r - 1) + 1 << " ";
      }
    }
    cout << '\n';
  }                                                                    
  return 0;
}