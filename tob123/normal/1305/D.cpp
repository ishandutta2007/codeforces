#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1010;

int N;
int NN;
vector<int> G[n];

bool vis[n];
int dist[n];
int AA, BB;

int query(int a, int b){
  cout << "? " << a+1 << " " << b+1 << endl;
  cin >> a;
  return a-1;
}

void dfs(int cur, int par){
  for(int x : G[cur]){
    if(!vis[x] && x != par){
      dist[x] = dist[cur]+1;
      dfs(x, cur);
    }
  }
}

bool rem(int cur, int par){
  bool d = cur == AA || cur == BB;
  for(int x : G[cur]){
    if(!vis[x] && x != par){
      d |= rem(x, cur);
    }
  }
  return d;
}

void remAll(int cur, int par){
  vis[cur] = true;
  NN--;
  for(int x : G[cur]){
    if(!vis[x] && x != par){
      remAll(x, cur);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  NN = N;
  for(int i=0; i<N-1; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  while(NN > 1){
    int a;
    for(int i=0; i<N; i++){
      if(!vis[i]){
        dfs(i, -1);
        a = i;
        break;
      }
    }
    for(int i=0; i<N; i++){
      if(!vis[i] && dist[i] > dist[a])
        a = i;
    }
    dfs(a, -1);
    int b = a;
    for(int i=0; i<N; i++){
      if(!vis[i] && dist[i] > dist[a])
        a = i;
    }
    int x = query(a, b);
    AA = a; BB = b;
    for(int z : G[x]){
      if(!vis[z]){
        if(rem(z, x))
          remAll(z, x);
      }
    }
  }
  for(int i=0; i<N; i++){
    if(!vis[i]){
      cout << "! " << i+1 << endl;
    }
  }

  return 0;
}