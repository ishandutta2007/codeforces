/**
 *    author:  wxhtzdy
 *    created: 21.06.2022 14:36:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<vector<tuple<int, int, int>>> g(n);
  const long long inf = 1e18;
  vector<vector<long long>> f(n, vector<long long>(n, inf));
  vector<int> u(m);
  vector<int> v(m);
  vector<int> w(m);  
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> w[i];
    --u[i]; --v[i];
    g[u[i]].emplace_back(v[i], w[i], i);
    g[v[i]].emplace_back(u[i], w[i], i);
    f[u[i]][v[i]] = f[v[i]][u[i]] = w[i];
  }
  for (int i = 0; i < n; i++) {
    f[i][i] = 0;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }
  int q;
  cin >> q;
  vector<int> a(q);
  vector<int> b(q);
  vector<int> l(q);                                                                
  vector<vector<int>> opt(n);
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i] >> l[i];
    --a[i]; --b[i];
    opt[a[i]].push_back(i);
  }
  vector<int> ans(m);
  for (int vv = 0; vv < n; vv++) {
    vector<long long> dist(n, inf);
    for (int j : opt[vv]) {
      dist[b[j]] = min(dist[b[j]], (long long) -l[j]);
    }
    set<pair<long long, int>> st;
    for (int i = 0; i < n; i++) {
      if (dist[i] != inf) {
        st.emplace(dist[i], i);
      }
    }
    for (int i = 0; i < n; i++) {
      if (dist[i] == inf) {
        continue;
      }
      for (int j = 0; j < n; j++) {
        dist[j] = min(dist[j], dist[i] + f[i][j]);
      }
    }
    for (int i = 0; i < m; i++) {
      if (-f[u[i]][vv] - w[i] >= dist[v[i]]) {
        ans[i] |= 1;
      }
      if (-f[v[i]][vv] - w[i] >= dist[u[i]]) {
        ans[i] |= 1;
      }
    }
  }
  cout << accumulate(ans.begin(), ans.end(), 0) << '\n';        
  return 0;
}