/**
 *    author:  milos
 *    created: 20.02.2021 00:51:23       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<tuple<int, int, int>> e;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    e.emplace_back(u, v, w);
  }
  sort(e.begin(), e.end(), [&](tuple<int, int, int> x, tuple<int, int, int> y){
    return get<2>(x) < get<2>(y);  
  });    
  vector<bool> was(n, false);
  vector<int> hash(n, 0);   
  for (int i = 0; i < min(m, k); i++) {
    was[get<0>(e[i])] = true;
    was[get<1>(e[i])] = true;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      hash[i] = cnt++;
    }
  }
  const long long inf = 1e16;
  vector<vector<long long>> dist(cnt, vector<long long>(cnt, inf));
  for (int i = 0; i < min(m, k); i++) {
    int u = hash[get<0>(e[i])], v = hash[get<1>(e[i])], w = get<2>(e[i]);
    //cout << u << " " << v << '\n';
    dist[u][v] = dist[v][u] = w;
  }   
  for (int l = 0; l < cnt; l++) {
    for (int i = 0; i < cnt; i++) {
      for (int j = 0; j < cnt; j++) {
        dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
      }
    }
  }
  vector<long long> p;
  for (int i = 0; i < cnt; i++) {
    for (int j = i + 1; j < cnt; j++) {
      p.push_back(dist[i][j]);
    }
  }
  sort(p.begin(), p.end());
  cout << p[k - 1] << '\n';
  return 0;
}