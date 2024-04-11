#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int N, M;
vector<vector<pii>> G;

//Runtime O(V^2 * E), for unitiy networks (e.g. bipartide matching) O(E*sqrt(V) + V^2)
//use capacity adjacency matrix cap
//G has to be undirected or in directed case: reverse edge with capacity 0

const int INF = 1e9;

vector<vector<int>> cap;
vector<int> level, ptr;
vector<vector<int>> fl;

bool bfs(int s, int t) {
  queue<int> q;
  level[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for(auto p : G[v]){
      int u = p.first;
      if(cap[v][u] > 0 && level[u] == -1){
        level[u] = level[v]+1;
        q.push(u);
      }
    }
  }
  return level[t] != -1;
}

int dfs(int v, int pushed, int t) {
  if (pushed == 0)
    return 0;
  if (v == t)
    return pushed;
  for (int& cid = ptr[v]; cid < (int)G[v].size(); cid++) {
    int u = G[v][cid].first;
    if (level[v]+1 != level[u] || cap[v][u] < 1)
      continue;
    int tr = dfs(u, min(pushed, cap[v][u]), t);
    if (tr == 0)
      continue;
    cap[v][u] -= tr;
    cap[u][v] += tr;
    fl[v][u] += tr;
    fl[u][v] -= tr;
    return tr;
  }
  return 0;
}

int maxflow(int s, int t){
  int N = G.size();
  level.resize(N);
  ptr.resize(N);
  cap = vector<vector<int>>(N, vector<int>(N));
  fl = vector<vector<int>>(N, vector<int>(N));
  for(int i=0; i<N; i++){
    for(auto p : G[i]){
      cap[i][p.first] += p.second;
    }
  }
  int f = 0;
  while (true){
    fill(level.begin(), level.end(), -1);
    if (!bfs(s, t))
      break;
    fill(ptr.begin(), ptr.end(), 0);
    while (int pushed = dfs(s, INF, t)){
      f += pushed;
    }
  }
  return f;
}

int main(){
  cin >> N >> M;
  G.resize(2*N+2);
  int suma = 0;
  for(int i=1; i<=N; i++){
    int x;
    cin >> x;
    G[0].push_back({i, x});
    G[i].push_back({0, 0});
    suma += x;
  }
  int sumb = 0;
  for(int i=1; i<=N; i++){
    int x;
    cin >> x;
    G[N+i].push_back({2*N+1, x});
    G[2*N+1].push_back({N+i, 0});
    sumb += x;
    G[i].push_back({N+i, INF});
    G[N+i].push_back({i, 0});
  }
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back({N+b, INF});
    G[N+b].push_back({a, 0});
    G[b].push_back({N+a, INF});
    G[N+a].push_back({b, 0});
  }

  int flow = maxflow(0, 2*N+1);
  if(flow == sumb && suma == sumb){
    cout << "YES" << endl;
    fl.resize(N+1);
    for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
        cout << fl[i][N+j] << " ";
      }
      cout << endl;
    }
  }
  else{
    cout << "NO" << endl;
  }

  return 0;
}