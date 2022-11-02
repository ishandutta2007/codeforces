#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

const int n = 2e5+10;

int T, N, M;
vector<int> G[n];
vector<int> G2[n];
bool inS[n];
bool vis[n];
vector<int> cnt, anc;
int L[n];
bool itr[n];
vector<int> res;

bool good(int cur){
  vis[cur] = true;
  inS[cur] = true;
  bool pos = true;
  for(int x : G[cur]){
    if(vis[x]){
      pos &= inS[x];
    }
    else if(!good(x))
      pos = false;
  }
  inS[cur] = false;
  return pos;
}

void dfs(int cur){
  vis[cur] = true;
  inS[cur] = true;
  cnt[cur] = 0;
  anc[cur] = cur;
  for(int x : G[cur]){
    if(vis[x]){
      anc[cur] = L[anc[cur]] >= L[x] ? x : anc[cur];
      cnt[cur]++;
    }
    else{
      L[x] = L[cur]+1;
      dfs(x);
      anc[cur] = L[anc[cur]] >= L[anc[x]] ? anc[x] : anc[cur];
      cnt[cur] += cnt[x];
    }
  }
  for(int x : G2[cur]){
    if(!inS[x])
      cnt[cur]--;
  }
  inS[cur] = false;
}

void dfs2(int cur){
  vis[cur] = true;
  inS[cur] = true;
  itr[cur] = cnt[cur] < 2 && (itr[anc[cur]] || anc[cur]==cur);
  if(itr[cur])
    res.push_back(cur);
  for(int x : G[cur]){
    if(!vis[x])
      dfs2(x);
  }
  inS[cur] = false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> M;
    cnt.resize(N); anc.resize(N);
    for(int i=0; i<N; i++){
      G[i].clear(); G2[i].clear();
      vis[i] = inS[i] = false;
      cnt[i] = 0;
    }
    for(int i=0; i<M; i++){
      int u, v;
      cin >> u >> v;
      u--; v--;
      G[u].push_back(v);
      G2[v].push_back(u);
    }
    mt19937 rng; // random generator
    uniform_int_distribution<int> unii(0, N-1);
    int x = -1;
    for(int i=0; i<100; i++){
      int st = unii(rng);
      for(int i=0; i<N; i++){
        vis[i] = inS[i] = false;
      }
      if(good(st)){
        x = st;
        break;
      }
    }
    if(x == -1){
      cout << -1 << "\n";
      continue;
    }
    for(int i=0; i<N; i++){
      vis[i] = inS[i] = false;
    }
    L[x] = 0;
    dfs(x);
    for(int i=0; i<N; i++){
      vis[i] = inS[i] = false;
    }
    res.clear();
    dfs2(x);
    //print(cnt);
    //print(anc);
    if(sz(res)*5 < N){
      cout << -1 << "\n";
      continue;
    }
    sort(res.begin(), res.end());
    for(int x : res){
      cout << x+1 << " ";
    }
    cout << "\n";
  }
}