#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxside = 3000;

int N, M;
vector<vector<pii>> G;
int ind[205];
vector<vector<pii>> f;

//Runtime O(V^2 * E), for unitiy networks (e.g. bipartide matching) O(E*sqrt(V) + V^2)
//use capacity adjacency matrix cap
//G has to be undirected or in directed case: reverse edge with capacity 0

const int INF = 1e9;

vector<vector<int>> cap;
vector<int> level, ptr;

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
    if (!bfs(s, t))
      break;
    fill(ptr.begin(), ptr.end(), 0);
    while (int pushed = dfs(s, INF, t)){
      f += pushed;
    }
  }
  return f;
}

void printG(){
  for(int i=0; i<G.size(); i++){
    cout << i << ": ";
    for(auto p : G[i]){
      cout << p.first << "(" << p.second << "), ";
    }
    cout << endl;
  }
}

vector<pii> factorize(int x){
  ll cur = x;
  vector<pii> res;
  for(ll i=2; i*i<=cur; i++){
    int cnt = 0;
    while(cur % i == 0){
      cur /= i;
      cnt++;
    }
    if(cnt > 0){
      res.push_back({i, cnt});
    }
  }
  if(cur > 1)
    res.push_back({cur, 1});
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  f.push_back({});
  G.resize(20*N+2);
  int curI = 2;
  for(int i=1; i<=N; i++){
    int a;
    cin >> a;
    ind[i] = curI;
    vector<pii> fact = factorize(a);
    for(int j=0; j<fact.size(); j++){
      G.push_back(vector<pii>());
      if(i%2){
        G[curI].push_back({1, fact[j].second});
        G[1].push_back({curI, 0});
      }
      else{
        G[0].push_back({curI, fact[j].second});
        G[curI].push_back({0, 0});
      }
      curI++;
    }
    f.push_back(fact);
  }
  G.resize(curI);
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    if(a % 2 == 1)
      swap(a, b);
    for(int k=0; k<f[a].size(); k++){
      for(int j=0; j<f[b].size(); j++){
        if(f[a][k].first == f[b][j].first){
          G[ind[a]+k].push_back({ind[b]+j, INF});
          G[ind[b]+j].push_back({ind[a]+k, 0});
        }
      }
    }
  }

  //printG();

  cout << maxflow(0, 1) << endl;

  return 0;
}