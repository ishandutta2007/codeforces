#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1010;
const int MOD = 9*8*7*5;

int N, Q;
int K[n];
int M[n];
vector<int> E[n];
int G[n][MOD];
int vis[n][MOD];
int res[n][MOD];

int cnt = 0;
int C[n];

int dfs2(int fx, int fc, int x, int c){
  int nxtX = G[x][c];
  int nxtC = ((c+K[x])%MOD + MOD) % MOD;
  C[x]++;
  if(C[x] == 1)
    cnt++;
  int res;
  if(nxtX == fx && nxtC == fc)
    res = cnt;
  else
    res = dfs2(fx, fc, nxtX, nxtC);
  if(C[x] == 1)
    cnt--;
  C[x]--;
  return res;
}

void dfs(int x, int c){
  vis[x][c] = 1;
  int nxtX = G[x][c];
  int nxtC = ((c+K[x])%MOD + MOD) % MOD;
  if(vis[nxtX][nxtC] == 0){
    //D[nxtX][nxtC] = D[x][c]+1;
    dfs(nxtX, nxtC);
    res[x][c] = res[nxtX][nxtC];
  }
  else if(vis[nxtX][nxtC] == 1){
    res[x][c] = dfs2(x, c, x, c);
  }
  else{
    res[x][c] = res[nxtX][nxtC];
  }
  vis[x][c] = 2;
}

int main(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> K[i];
  }
  for(int i=0; i<N; i++){
    cin >> M[i];
    for(int j=0; j<M[i]; j++){
      int x;
      cin >> x;
      x--;
      E[i].push_back(x);
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<MOD; j++){
      G[i][j] = E[i][((j+K[i])%MOD + MOD)%M[i]];
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<MOD; j++){
      if(vis[i][j] == 0)
        dfs(i, j);
    }
  }

  cin >> Q;
  for(int i=0; i<Q; i++){
    int x, y;
    cin >> x >> y;
    x--;
    cout << res[x][(y%MOD + MOD)%MOD] << "\n";
  }

  return 0;
}