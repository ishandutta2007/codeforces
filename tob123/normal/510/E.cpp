#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int n = 500;

int N;
vector<int> A;
vector<vector<pii>> G;
bool vis[n];
vector<int> res;

//Runtime O(V^2 * E), for unitiy networks (e.g. bipartide matching) O(E*sqrt(V) + V^2)
//use capacity adjacency matrix cap
//G has to be undirected or in directed case: reverse edge with capacity 0

const int INF = 1e9;

vector<vector<int>> cap;
vector<int> level, ptr;

bool mf_bfs(int s, int t) {
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

int fl_dfs(int v, int pushed, int t) {
  if (pushed == 0)
    return 0;
  if (v == t)
    return pushed;
  for (int& cid = ptr[v]; cid < (int)G[v].size(); cid++) {
    int u = G[v][cid].first;
    if (level[v]+1 != level[u] || cap[v][u] < 1)
      continue;
    int tr = fl_dfs(u, min(pushed, cap[v][u]), t);
    if (tr == 0)
      continue;
    cap[v][u] -= tr;
    cap[u][v] += tr;
    return tr;
  }
  return 0;
}

int maxflow(int s, int t){
  int N = G.size();
  level.resize(N);
  ptr.resize(N);
  cap = vector<vector<int>>(N, vector<int>(N));
  for(int i=0; i<N; i++){
    for(auto p : G[i]){
      cap[i][p.first] += p.second;
    }
  }
  int f = 0;
  while (true){
    fill(level.begin(), level.end(), -1);
    if (!mf_bfs(s, t))
      break;
    fill(ptr.begin(), ptr.end(), 0);
    while (int pushed = fl_dfs(s, INF, t)){
      f += pushed;
    }
  }
  return f;
}

void dfs(int cur){
  vis[cur] = true;
  res.push_back(cur);
  for(auto p : G[cur]){
    if(p.first >= N)
      continue;
    int f = p.second - cap[cur][p.first];
    if(abs(f) == 1 && !vis[p.first]){
      dfs(p.first);
    }
  }
}

bool isPrime(int x){
  for(int i=2; i*i<=x; i++){
    if(x%i == 0)
      return false;
  }
  return true;
}

int main(){
  cin >> N;
  A.resize(N);
  G.resize(N+2);
  for(int i=0; i<N; i++){
    cin >> A[i];
    if(A[i]%2){
      G[i].push_back({N+1, 2});
      G[N+1].push_back({i, 0});
    }
    else{
      G[N].push_back({i, 2});
      G[i].push_back({N, 0});
    }
  }

  for(int i=0; i<N; i++){
    if(A[i]%2)
      continue;
    for(int j=0; j<N; j++){
      if(A[j]%2 == 0)
        continue;
      if(isPrime(A[i]+A[j])){
        G[i].push_back({j, 1});
        G[j].push_back({i, 0});
      }
    }
  }

  int flow = maxflow(N, N+1);
  if(flow == N){
    vector<vector<int>> R;
    for(int i=0; i<N; i++){
      if(!vis[i]){
        dfs(i);
        R.push_back(res);
        res.clear();
      }
    }
    cout << R.size() << endl;
    for(auto res : R){
      cout << res.size();
      for(int x : res){
        cout << " " << x+1;
      }
      cout << endl;
    }
  }
  else{
    cout << "Impossible" << endl;
  }

  return 0;
}