#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,ll> pii;
typedef long double ld;

int N, M, X;
vector<vector<pii>> G;
ld scale;

//Runtime O(V^2 * E), for unitiy networks (e.g. bipartide matching) O(E*sqrt(V) + V^2)
//use capacity adjacency matrix cap
//G has to be undirected or in directed case: reverse edge with capacity 0

const ll INF = 1e18;

vector<vector<ll>> cap;
vector<ll> level, ptr;

bool mf_bfs(ll s, ll t) {
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

ll mf_dfs(ll v, ll pushed, ll t) {
  if (pushed == 0)
    return 0;
  if (v == t)
    return pushed;
  for (ll& cid = ptr[v]; cid < (ll)G[v].size(); cid++) {
    ll u = G[v][cid].first;
    if (level[v]+1 != level[u] || cap[v][u] < 1)
      continue;
    ll tr = mf_dfs(u, min(pushed, cap[v][u]), t);
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
  cap[0][1] = X;
  for(ll i=1; i<N; i++){
    for(auto p : G[i]){
      cap[i][p.first] += (ll) (((ld) p.second)/scale);
    }
  }
  ll f = 0;
  while (true){
    fill(level.begin(), level.end(), -1);
    if (!mf_bfs(s, t))
      break;
    fill(ptr.begin(), ptr.end(), 0);
    while (ll pushed = mf_dfs(s, INF, t)){
      f += pushed;
    }
  }
  return f;
}

ld error(ld a, ld b){
  return abs(a-b) / max((ld)1.0, b);
}

int main(){
  cin >> N >> M >> X;
  G.resize(N+1);
  for(int i=0; i<M; i++){
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back({b, w});
    G[b].push_back({a, 0});
  }

  G[0].push_back({1, X});
  G[1].push_back({0, 0});
  ld l=1e-7, r=2000000;
  while(error(l*X, r*X) > 1e-10){
    scale = (l+r)/2;
    ll fl = maxflow(0, N);
    //cout << scale << " -> " << fl << endl;
    if(fl == X){
      l = scale;
    }
    else{
      r = scale;
    }
  }

  cout << setprecision(20) << fixed << l*X << endl;

  return 0;
}