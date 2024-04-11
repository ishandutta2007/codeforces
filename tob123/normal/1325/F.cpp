#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;

int N, M;
vector<int> G[n];
int D[n]; //depth
bool ind[n]; //part of independent set?
bool found;
int P[n];

void dfs(int cur, int par){
  P[cur] = par;
  ll cntBack = 0;
  bool curInd = true;
  for(int x : G[cur]){
    if(D[x] == -1){
      D[x] = D[cur]+1;
      dfs(x, cur);
    }
    if(D[x] > D[cur])
      curInd &= !ind[x];
    else
      cntBack++;
  }
  if((cntBack+1)*(cntBack+1) >= N){ //cycle of len sqrt(N) found
    if(!found){
      found = true;
      int bst = G[cur][0];
      for(int x : G[cur]){
        if(D[x] < D[bst])
          bst = x;
      }
      vector<int> res;
      res.push_back(cur);
      while(cur != bst){
        cur = P[cur];
        res.push_back(cur);
      }
      cout << "2\n" << sz(res) << "\n";
      for(int x : res)
        cout << x+1 << " ";
      cout << endl;
    }
  }
  else if(curInd){
    ind[cur] = true;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  fill_n(D, N, -1);
  dfs(0, -1);
  if(!found){
    cout << "1\n";
    ll cnt = 0;
    for(int i=0; i<N && cnt*cnt < N; i++){
      if(ind[i]){
        cout << i+1 << " ";
        cnt++;
      }
    }
    cout << endl;
  }

  return 0;
}