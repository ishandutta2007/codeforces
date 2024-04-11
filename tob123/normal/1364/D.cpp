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

const int MAXN = 2e5+10;

int N, M, K;
bool vis[MAXN];
vector<vector<int>> G;
int cnt = 0;
int T;
vector<int> X;
int ind[MAXN];
int inS[MAXN];
bool inX[MAXN];

bool dfs1(int cur, int par){
  ind[cur] = sz(X);
  X.push_back(cur);
  inS[cur] = true;
  vis[cur] = true;
  for(int x : G[cur]){
    if(x == par)
      continue;
    if(vis[x] && inS[x]){
      auto st = X.begin(); st += ind[x];
      X = vector<int>(st, X.end());
      return true;
    }
    if(!vis[x] && dfs1(x, cur))
      return true;
  }
  X.pop_back();
  inS[cur] = false;
  return false;
}

bool dfs3(int cur, int par){
  bool res = false;
  for(int x : G[cur]){
    if(x != par){
      res |= dfs3(x, cur);
    }
  }
  if(!res && cnt<(K+1)/2){
    X.push_back(cur);
    cnt++;
  }
  return !res;
}

void clean(){
  //print(X);
  if(sz(X) <= K){
    T = 2;
    return;
  }
  int n = sz(X);
  for(int i=0; i<n; i++)
    inX[X[i]] = true;
  for(int i=0; i<n; i++){
    for(int x : G[X[i]]){
      if(x != X[(i+n-1)%n] && x != X[(i+1)%n] && inX[x]){
        //cout << "split at " << X[i] << " " << x << endl;
        for(int i=0; i<n; i++)
          inX[X[i]] = false;
        int ind = -1;
        for(int k=0; k<n; k++)
          if(X[k] == x) ind=k;
        vector<int> nxtX;
        int st=i, to=ind;
        if((i+n-ind)%n < (ind+n-i)%n){
          st=ind; to=i;
        }
        for(int k=st; k!=to; k=(k+1)%n){
          nxtX.push_back(X[k]);
        }
        nxtX.push_back(X[to]);
        X = move(nxtX);
        clean();
        return;
      }
    }
  }
  T = 1;
  vector<int> res;
  for(int i=0; i<sz(X)-1 && sz(res)<(K+1)/2; i+=2)
    res.push_back(X[i]);
  X = move(res);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> K;
  G.resize(N);
  for(int i=0; i<M; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if(M == N-1){
    T = 1;
    dfs3(0, -1);
  }
  else{
    dfs1(0, -1);
    clean();
  }

  cout << T << "\n";
  if(T == 2)
    cout << sz(X) << "\n";
  for(int x : X){
    cout << x+1 << " ";
  }
  cout << "\n";
}