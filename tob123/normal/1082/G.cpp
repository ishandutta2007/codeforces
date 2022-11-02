#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

const ll n = 1e4;

ll N, M;
vector<vector<pii>> G;

//Runtime O(V^2 * E), for simple unitiy networks (e.g. bipartide matching) O(E*sqrt(V))
//use capacity adjacency matrix cap
//G has to be undirected or in directed case: reverse edge with capacity 0

const ll INF = 1e15;

vector<vector<ll>> cap;
vector<ll> level, ptr;

bool bfs(ll s, ll t) {
  queue<ll> q;
  level[s] = 0;
  q.push(s);
  while (!q.empty()) {
    ll v = q.front();
    q.pop();
    for(auto p : G[v]){
      ll u = p.first;
      if(cap[v][u] > 0 && level[u] == -1){
        level[u] = level[v]+1;
        q.push(u);
      }
    }
  }
  return level[t] != -1;
}

ll dfs(ll v, ll pushed, ll t) {
  if (pushed == 0)
    return 0;
  if (v == t)
    return pushed;
  for (ll& cid = ptr[v]; cid < (ll)G[v].size(); cid++) {
    ll u = G[v][cid].first;
    if (level[v]+1 != level[u] || cap[v][u] < 1)
      continue;
    ll tr = dfs(u, min(pushed, cap[v][u]), t);
    if (tr == 0)
      continue;
    cap[v][u] -= tr;
    cap[u][v] += tr;
    return tr;
  }
  return 0;
}

ll maxflow(ll s, ll t){
  ll N = G.size();
  level.resize(N);
  ptr.resize(N);
  cap = vector<vector<ll>>(N, vector<ll>(N));
  for(ll i=0; i<N; i++){
    for(auto p : G[i]){
      cap[i][p.first] += p.second;
    }
  }
  ll f = 0;
  while (true){
    fill(level.begin(), level.end(), -1);
    if (!bfs(s, t))
      break;
    fill(ptr.begin(), ptr.end(), 0);
    while (ll pushed = dfs(s, INF, t)){
      f += pushed;
    }
  }
  return f;
}

void addEdge(ll a, ll b, ll cap){
  G[a].push_back({b, cap});
  G[b].push_back({a, 0});
}

void prllG(){
  for(ll i=0; i<G.size(); i++){
    for(auto p : G[i]){
      if(p.second == INF)
        p.second = -1;
      cout << i << " " << p.first << " " << p.second << endl;
    }
  }
}

int main(){
  cin >> N >> M;
  G.resize(N+M+2);
  ll sum = 0;
  for(ll i=1; i<=N; i++){
    ll a;
    cin >> a;
    addEdge(i, N+M+1, a);
  }
  for(ll i=1; i<=M; i++){
    ll u, v, w;
    cin >> u >> v >> w;
    sum += w;
    addEdge(N+i, u, INF);
    addEdge(N+i, v, INF);
    addEdge(0, N+i, w);
  }
  //prllG();

  //cout << sum << endl;
  cout << sum-maxflow(0, N+M+1) << endl;

  return 0;
}