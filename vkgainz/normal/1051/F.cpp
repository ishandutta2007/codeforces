#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 1e5+5;

int n, m;
vector<pair<int, int>> adj[MX];
int d[MX];
int tab[MX][17];
ll tabDist[MX][17];
ll h[MX];
struct edge {
  int u, v;
  int w;
  edge(int a, int b, int c):
    u(a), v(b), w(c)
  {
  }
};
vector<edge> back;
vector<vector<ll>> totDist;
void dijkstra(int src) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  vector<ll> dist(MX);
  fill(dist.begin(), dist.end(), 1e15);
  dist[src] = 0;
  pq.push({0, src});
  while(!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    for(auto next : adj[v]) {
      if(dist[v] + next.s < dist[next.f]) {
        dist[next.f] = dist[v] + next.s;
        pq.push({dist[next.f], next.f});
      }
    }
  }
  totDist.push_back(dist);
}
void dfs(int curr) {
  for(auto next : adj[curr]) {
    if(d[next.f]==0) {
      d[next.f] = d[curr] + 1;
      h[next.f] = h[curr] + next.s;
      tab[next.f][0] = curr;
      tabDist[next.f][0] = next.s;
      dfs(next.f);
    }
    else if(d[next.f] < d[curr] - 1) {
      back.push_back(edge(curr, next.f, next.s));
    }
  }
}
int lca(int u, int v) {
  if(d[u]>d[v])
    swap(u, v);
  for(int bit=16;bit>=0;bit--) {
    if(d[v]-(1<<bit)>=d[u])
      v = tab[v][bit];
  }
  if(v==u) return v;
  for(int bit=16;bit>=0;bit--) {
    if(tab[v][bit]!=tab[u][bit])
      v = tab[v][bit], u = tab[u][bit];
  }
  return tab[v][0];
}
ll getDist(int u, int v) {
  int l = lca(u, v);
  return h[u] + h[v] - 2*h[l];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for(int i=0;i<m;i++) {
    int u, v, w; cin >>u >> v >> w;
    --u, --v;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  d[0] = 1;
  dfs(0);
  for(int j=1;j<17;j++) {
    for(int i=0;i<n;i++) {
      tab[i][j] = tab[ tab[i][j-1] ][j-1];
      tabDist[i][j] = tabDist[i][j-1] + tabDist[ tab[i][j-1] ][j-1];
    }
  }
  for(int i=0;i<back.size();i++) {
    dijkstra(back[i].u);
    dijkstra(back[i].v);
  }
  int q; cin >> q;
  vector<ll> ret;
  while(q--) {
    int u, v; cin >> u >> v;
    --u, --v;
    ll ans = getDist(u,v);
    int x = 0;
    for(int i=0;i<back.size();i++) {
      ll cmp = totDist[x][u] + back[i].w + totDist[x+1][v];
      cmp = min(cmp, totDist[x+1][u] + back[i].w + totDist[x][v]);
      ans = min(ans, cmp);
      x+=2;
    }
    ret.push_back(ans);
  }
  for(auto &it : ret)
    cout << it << "\n";
}