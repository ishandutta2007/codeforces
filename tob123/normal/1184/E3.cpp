#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef tuple<int,int,int> tii;
typedef pair<int,int> pii;

const int n = 1e5 + 10;
const int m = 1e6 + 10;

int N, M;
vector<pii> G[n];
bool vis[n];
map<pii, int> MI;
bool inMST[m];
//int E[n];
int W[m];
pii toE[m];

int jmp[20][n];
int jmpC[20][n];
int jmpU[20][n];
int L[n];
vector<pii> T[n];
int P[n];
int R[m];

void dfs(int cur, int par, int cst){
  jmp[0][cur] = par;
  jmpC[0][cur] = cst;
  for(auto p : T[cur]){
    if(p.second != par){
      L[p.second] = L[cur]+1;
      dfs(p.second, cur, p.first);
    }
  }
}

void makeLCA(){
  dfs(0, 0, 0);
  for(int i=0; i<20; i++){
    for(int j=0; j<N; j++){
      jmpU[i][j] = 1000000000;
    }
  }
  for(int i=1; i<20; i++){
    for(int j=0; j<N; j++){
      jmp[i][j] = jmp[i-1][jmp[i-1][j]];
      jmpC[i][j] = max(jmpC[i-1][j], jmpC[i-1][jmp[i-1][j]]);
    }
  }
}

int lcaC(int a, int b, int updC){
  if(L[a] < L[b])
    swap(a, b);
  int res = 0;
  for(int i=19; i>=0; i--){
    if(L[jmp[i][a]] > L[b]){
      res = max(res, jmpC[i][a]);
      jmpU[i][a] = min(jmpU[i][a], updC);
      a = jmp[i][a];
    }
  }
  //cout << a+1 << ", " << b+1 << ", " << res << endl;
  if(L[a] != L[b]){
    res = max(res, jmpC[0][a]);
    jmpU[0][a] = min(jmpU[0][a], updC);
    a = jmp[0][a];
  }
  for(int i=19; i>=0; i--){
    if(jmp[i][a] != jmp[i][b]){
      res = max(res, jmpC[i][a]);
      res = max(res, jmpC[i][b]);
      jmpU[i][a] = min(jmpU[i][a], updC);
      jmpU[i][b] = min(jmpU[i][b], updC);
      a = jmp[i][a];
      b = jmp[i][b];
    }
  }
  if(a != b){
    res = max(res, jmpC[0][a]);
    res = max(res, jmpC[0][b]);
    jmpU[0][a] = min(jmpU[0][a], updC);
    jmpU[0][b] = min(jmpU[0][b], updC);
    a = jmp[0][a];
    b = jmp[0][b];
  }
  //cout << "lca: " << a+1 << " " << b+1 << endl;
  return res;
}

void updateLCA(){
  for(int i=19; i>0; i--){
    for(int j=0; j<N; j++){
      //jmpU[i][j] = max(jmpU[i][j], max(jmpU[i-1][j], jmpU[i-1][jmp[i-1][j]]));
      jmpU[i-1][j] = min(jmpU[i-1][j], jmpU[i][j]);
      jmpU[i-1][jmp[i-1][j]] = min(jmpU[i-1][jmp[i-1][j]], jmpU[i][j]);
    }
  }
}

pii toP(int a, int b){
  return make_pair(min(a,b), max(a,b));
}

int main(){
  cin >> N >> M;
  int a, b, e;
  for(int i=0; i<M; i++){
    cin >> a >> b >> e;
    a--; b--;
    G[a].push_back({e, b});
    G[b].push_back({e, a});
    MI[toP(a,b)] = i;
    toE[i] = toP(a, b);
    W[i] = e;
  }
  priority_queue<tii, vector<tii>, greater<tii>> PQ;
  PQ.push({0, 0, 0});
  while(!PQ.empty()){
    tie(e, a, b) = PQ.top();
    PQ.pop();
    if(vis[a]){
      continue;
    }
    vis[a] = true;
    if(a != b)
      inMST[MI[toP(a, b)]] = true;
    for(auto p : G[a]){
      if(!vis[p.second]){
        PQ.push(make_tuple(p.first, p.second, a));
      }
      /*
      else{
        E[MI[toP(a, p.second)]] = e;
      }
      */
    }
  }
  for(int i=0; i<M; i++){
    if(inMST[i]){
      T[toE[i].first].push_back({W[i], toE[i].second});
      T[toE[i].second].push_back({W[i], toE[i].first});
    }
  }
  /*
  for(int i=0; i<N; i++){
    for(int j=0; j<
  }
  */
  makeLCA();
  /*
  for(int i=0; i<3; i++){
    for(int j=0; j<N; j++){
      cout << jmp[i][j] << " ";
    }
    cout << endl;
  }
  for(int i=0; i<N; i++)
    cout << L[i] << " ";
  cout << endl;
  */

  for(int i=0; i<M; i++){
    if(!inMST[i]){
      //cout << toE[i].first+1 << " " << toE[i].second+1 << ": ";
      R[i] = lcaC(toE[i].first, toE[i].second, W[i]);
    }
  }
  updateLCA();
  for(int i=0; i<M; i++){
    //cout << toE[i].first+1 << ", " << toE[i].second+1 << ": ";
    if(inMST[i]){
      int a = toE[i].first;
      int b = toE[i].second;
      if(L[a] < L[b])
        swap(a,b);
      cout << jmpU[0][a] << "\n";
    }
    else{
      cout << R[i] << "\n";
    }
  }

  return 0;
}