#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> u(m);
  vector<int> v(m);
  vector<int> w(m);
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> w[i];
    --u[i]; --v[i];
  }
  vector<int> order(m);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return w[i] < w[j];
  });
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  vector<int> sz(n, 1);
  function<int(int)> get = [&](int x) {
    return p[x] == x ? x : p[x] = get(p[x]);
  };     
  function<bool(int, int)> unite = [&](int x, int y) {
    x = get(x);
    y = get(y);
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    if (x == y) {
      return false;
    }
    p[x] = y;
    sz[y] += sz[x];
    return true;
  };
  for (int i = 0; i < m; i++) {
    int ptr = i;
    while (ptr + 1 < m && w[order[ptr + 1]] == w[order[ptr]]) {
      ptr += 1;
    }                   
    for (int j = i; j <= ptr; j++) {
      int q = order[j];
      u[q] = get(u[q]);
      v[q] = get(v[q]);
    }
    for (int j = i; j <= ptr; j++) {
      int q = order[j];
      unite(u[q], v[q]);
    }
    i = ptr;
  }
  map<int, vector<int>> mp;
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    vector<int> id(k);
    set<int> all;
    mp.clear();
    for (int i = 0; i < k; i++) {
      cin >> id[i];
      --id[i];
      mp[w[id[i]]].push_back(id[i]);
      all.insert(w[id[i]]);
      p[u[id[i]]] = u[id[i]];
      p[v[id[i]]] = v[id[i]];
      sz[u[id[i]]] = 1;
      sz[v[id[i]]] = 1;
    }
    bool ok = true;
    for (int x : all) {
      for (auto i : mp[x]) {
        ok &= unite(u[i], v[i]);
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}