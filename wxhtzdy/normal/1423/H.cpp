/**
 *    author: m371
 *    created: 10.10.2021 14:01:49
**/
#include <bits/stdc++.h>

using namespace std;

struct dsu {
  vector<int> par;
  vector<int> sz;
  dsu(int n) {
    par.resize(n);
    sz.resize(n);
    iota(par.begin(), par.end(), 0);
    for (int i = 0; i < n; i++) {
      sz[i] = 1;
    }
  }
  int root(int u) {
    return par[u] == u ? u : root(par[u]);
  }
  stack<tuple<int, int, int, int>> stk;
  void unite(int x, int y) {
    x = root(x); y = root(y);
    stk.push({x, y, sz[x], sz[y]});
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
  }
  void rollback() {
    auto op = stk.top();
    stk.pop();
    int u = get<0>(op);
    int v = get<1>(op);
    par[u] = u;
    par[v] = v;
    sz[u] = get<2>(op);
    sz[v] = get<3>(op);
  }
};    

const int N = 543210;

vector<pair<int, int>> qs[N];
vector<pair<int, int>> st[4 * N];
dsu d(N + 5);

void add(int node, int l, int r, int ll, int rr, pair<int, int> ed) {
  if (l > r || ll > rr || l > rr || r < ll) return;
  if (ll <= l && r <= rr) {
    st[node].emplace_back(ed);
    return;
  }
  int mid = l + r >> 1;
  add(node + node, l, mid, ll, rr, ed);
  add(node + node + 1, mid + 1, r, ll, rr, ed);
}

void solve(int node, int l, int r) {
  if (l > r) return;
  for (auto ed : st[node]) {
    d.unite(ed.first, ed.second); 
  }
  if (l == r) {
    for (auto op : qs[l]) {
      if (op.second == -1) {
        cout << d.sz[d.root(op.first)] << '\n';
      } else {
        d.unite(op.first, op.second);
      }
    }
    for (auto op : qs[l]) {
      if (op.second != -1) {
        d.rollback();
      }
    }
  } else {
    int mid = l + r >> 1;
    solve(node + node, l, mid);
    solve(node + node + 1, mid + 1, r);
  }
  for (auto ed : st[node]) {
    d.rollback();
  }
}
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q, k;
  cin >> n >> q >> k;
  int day = 0;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      add(1, 0, N - 1, day + 1, day + k - 1, {x, y});
      qs[day].push_back({x, y});
    } else if (t == 2) {
      int x;
      cin >> x;
      --x;
      qs[day].push_back({x, -1});
    } else {
      day++;
    }
  }
  solve(1, 0, N - 1);  
  return 0;
}