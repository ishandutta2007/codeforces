/**
 *    author:  tourist
 *    created: 13.06.2021 19:26:37       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    int f;
    cin >> f;
    cout << "! 1 1" << endl;
    return 0;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> sub(n + 1);
  function<void(int, int)> Dfs = [&](int v, int pr) {
    vector<int> children;
    for (int u : g[v]) {
      if (u == pr) {
        continue;
      }
      Dfs(u, v);
      children.push_back(max(1, sub[u]));
    }
    sort(children.rbegin(), children.rend());
    int sz = (int) children.size();
    for (int i = 0; i < sz; i++) {
      sub[v] = max(sub[v], children[i] + i);
    }
    sub[v] = max(sub[v], sz);
  };
  Dfs(0, -1);
  vector<int> save(n, -1);
  vector<int> pv(n, -1);
  int res = 0;
  function<void(int, int, int)> Solve = [&](int v, int pr, int up) {
    pv[v] = pr;
    save[v] = up;
    vector<int> children;
    for (int u : g[v]) {
      if (u == pr) {
        continue;
      }
      children.push_back(u);
    }
    if (up != -1) {
      sub[n] = up;
      children.push_back(n);
    }
    sort(children.begin(), children.end(), [&](int i, int j) {
      return sub[i] > sub[j];
    });
    int sz = (int) children.size();
    if (sz == 1) {
      res = max(res, max(1, sub[children[0]]));
    } else {
      for (int i = 1; i < sz; i++) {
        int cur = max(1, sub[children[0]]) + max(1, sub[children[i]]) + (i - 1);
        res = max(res, cur);
      }
      int cur = max(1, sub[children[0]]) + (sz - 1);
      res = max(res, cur);
    }
    vector<int> pref(sz);
    for (int i = 0; i < sz; i++) {
      pref[i] = max(1, sub[children[i]]) + i;
      if (i > 0) pref[i] = max(pref[i], pref[i - 1]);
    }
    vector<int> suf(sz);
    for (int i = sz - 1; i >= 0; i--) {
      suf[i] = max(1, sub[children[i]]) + (i - 1);
      if (i < sz - 1) suf[i] = max(suf[i], suf[i + 1]);
    }
    for (int i = 0; i < sz; i++) {
      if (children[i] == n) {
        continue;
      }
      int mx = sz - 1;
      if (i > 0) mx = max(mx, pref[i - 1]);
      if (i < sz - 1) mx = max(mx, suf[i + 1]);
      Solve(children[i], v, mx);
    }
  };
  Solve(0, -1, -1);
  cout << res << endl;
  int root;
  cin >> root;
  --root;
  sub.assign(n, -1);
  vector<vector<pair<int, int>>> tyk(n);
  function<void(int, int)> Dfs2 = [&](int v, int pr) {
    vector<int> children;
    for (int u : g[v]) {
      if (u == pr) {
        continue;
      }
      Dfs2(u, v);
      children.push_back(u);
    }
    sort(children.begin(), children.end(), [&](int i, int j) {
      return sub[i] > sub[j];
    });
    int sz = (int) children.size();
    for (int i = 0; i < sz; i++) {
      tyk[v].emplace_back(tyk[children[i]].empty() ? children[i] : tyk[children[i]][0].first, children[i]);
      sub[v] = max(sub[v], max(1, sub[children[i]]) + i);
    }
    sub[v] = max(sub[v], sz);
  };
  Dfs2(root, -1);
  int qs = 0;
  auto Ask = [&](int x) {
    ++qs;
    assert(qs <= res);
    cout << "? " << x + 1 << endl;
    int y;
    cin >> y;
    --y;
    return y;
  };
  function<int(int, int, int, int)> Get = [&](int v, int pr, int q, int w) {
    if (w != v) {
      assert(!tyk[v].empty());
      assert(q == tyk[v][0].first);
      return Get(tyk[v][0].second, v, q, w);
    }
    if (tyk[v].empty()) {
      return v;
    }
    for (auto& p : tyk[v]) {
      if (p.first == q) {
        continue;
      }
      int z = Ask(p.first);
      if (z != v) {
        return Get(p.second, v, p.first, z);
      }
    }
    return v;
  };
  int a = -1, b = -1;
  for (auto& p : tyk[root]) {
    int z = Ask(p.first);
    if (z != root) {
      if (a == -1) a = Get(p.second, root, p.first, z);
      else b = Get(p.second, root, p.first, z);
      if (a != -1 && b != -1) break;
    }
  }
  if (a == -1) a = root;
  if (b == -1) b = root;
  cout << "! " << a + 1 << " " << b + 1 << endl;
  return 0;
}