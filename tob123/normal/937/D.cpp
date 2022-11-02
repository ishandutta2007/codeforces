#include <bits/stdc++.h>
using namespace std;

int N, M, S;
vector<vector<int>> G;
vector<bool> vis, inS;
vector<int> last;
int endNode;

bool bfs(){
  queue<int> Q;
  Q.push(S);
  vis[S] = true;
  last[S] = -1;
  while(!Q.empty()){
    int cur = Q.front()%N;
    int lev = Q.front()/N;
    Q.pop();
    if(G[cur].size() == 0 && lev == 1){
      endNode = lev*N + cur;
      return true;
    }
    int newLev = 1-lev;
    for(int x : G[cur]){
      int newV = newLev*N + x;
      if(!vis[newV]){
        vis[newV] = true;
        last[newV] = lev*N + cur;
        Q.push(newV);
      }
    }
  }
  return false;
}

bool dfs(int cur){
  vis[cur] = true;
  inS[cur] = true;
  int node = cur%N;
  int lev = cur/N;
  int newLev = 1-lev;
  for(int x : G[node]){
    int newV = newLev*N + x;
    if(inS[newV]){
      return true;
    }
    if(!vis[newV]){
      if(dfs(newV)){
        return true;
      }
    }
  }
  inS[cur] = false;
  return false;
}

bool hasCycle(){
  fill(vis.begin(), vis.end(), false);
  inS.resize(2*N);
  return dfs(S);
}

int main(){
  cin >> N >> M;
  G.resize(N);
  vis.resize(2*N);
  last.resize(2*N);
  for(int i=0; i<N; i++){
    int c, x;
    cin >> c;
    for(int j=0; j<c; j++){
      cin >> x;
      G[i].push_back(x-1);
    }
  }
  cin >> S;
  S--;
  if(bfs()){
    cout << "Win" << endl;
    /*
    for(int i=0; i<2*N; i++){
      cout << last[i] << " ";
    }
    cout << endl;
    cout << endNode << endl;
    exit(0);
    */
    stack<int> S;
    int cur = endNode;
    while(cur != -1){
      S.push(cur%N);
      cur = last[cur];
    }
    while(!S.empty()){
      cout << S.top()+1 << " ";
      S.pop();
    }
    cout << endl;
  }
  else if(hasCycle()){
    cout << "Draw" << endl;
  }
  else{
    cout << "Lose" << endl;
  }

  return 0;
}