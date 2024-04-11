#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e4+10;

int N, M;
vector<pii> G[n];
int cnt, D[n];
bool vis[n];
vector<int> R;

void dfs(int cur, int par){
  for(auto p : G[cur]){
    int x, ind; tie(x, ind) = p;
    if(D[x] == -1){
      D[x] = D[cur]+1;
      dfs(x, cur);
    }
    cnt += D[x]%2 == D[cur]%2;
  }
}

pair<int,int> add(pii a, pii b){
  return {a.first+b.first, a.second+b.second};
}

pair<int,int> dfs2(int cur, int par){
  vis[cur] = true;
  pii res = {};
  int pi;
  for(auto p : G[cur]){
    int x, ind; tie(x,ind) = p;
    if(x == par){
      pi = ind;
      continue;
    }
    if(!vis[x]){
      res = add(res, dfs2(x, cur));
    }
    else if(D[x]%2 == D[cur]%2){
      if(D[x] > D[cur]){
        res.first--;
      }
      else{
        res.first++;
        if(cnt == 1){
          R.push_back(ind);
        }
      }
    }
    else{
      if(D[x] > D[cur]){
        res.second--;;
      }
      else{
        res.second++;
      }
    }
  }
  if(res.first == cnt && res.second == 0){
    R.push_back(pi);
  }

  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back({v,i});
    G[v].push_back({u,i});
  }
  vector<int> cmp;
  fill_n(D, N, -1);
  for(int i=0; i<N; i++){
    if(D[i] == -1){
      cmp.push_back(i);
      D[i] = 0;
      dfs(i, -1);
    }
  }
  cnt /= 2;
  if(cnt == 0){
    cout << M << endl;
    for(int i=1; i<=M; i++)
      cout << i << " ";
    cout << endl;
    return 0;
  }
  for(int x : cmp){
    dfs2(x, -1);
  }
  sort(R.begin(), R.end());
  cout << sz(R) << endl;
  for(int x : R){
    cout << x+1 << " ";
  }
  cout << endl;

  return 0;
}