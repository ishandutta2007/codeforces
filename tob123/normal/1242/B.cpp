#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;

int N, M;
set<int> G[n];
bool vis[n];
set<int> S, x;

void dfs(int cur){
  vector<int> nxt;
  for(int a : x){
    if(G[cur].count(a) == 0){
      nxt.push_back(a);
    }
  }
  for(int a : nxt){
    vis[a] = true;
    S.erase(a);
    x.erase(a);
  }
  for(int a : nxt){
    dfs(a);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].insert(b);
    G[b].insert(a);
  }
  for(int i=0; i<N; i++){
    S.insert(i);
  }
  int cnt = 0;
  for(int i=0; i<N; i++){
    if(!vis[i]){
      cnt++;
      vis[i] = true;
      x = S;
      dfs(i);
    }
  }
  cout << cnt-1 << endl;

  return 0;
}