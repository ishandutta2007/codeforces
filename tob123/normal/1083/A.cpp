#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,ll> pii;

const int n = 3e5+10;

int N;
ll W[n];
vector<pii> G[n];

ll in[n], in2[n], inNode[n];
bool vis[n];

void dfs1(int cur){
  vis[cur] = true;
  in[cur] = W[cur];
  in2[cur] = W[cur];
  inNode[cur] = -1;
  for(auto x : G[cur]){
    if(!vis[x.first]){
      dfs1(x.first);
      ll val = W[cur] + in[x.first] - x.second;
      if(val > in[cur]){
        in2[cur] = in[cur];
        in[cur] = val;
        inNode[cur] = x.first;
      }
      else if(val > in2[cur]){
        in2[cur] = val;
      }
    }
  }
}

void dfs2(int cur){
  vis[cur] = true;
  for(auto x : G[cur]){
    if(!vis[x.first]){
      ll val;
      if(x.first != inNode[cur]){
        val = W[x.first] + in[cur] - x.second;
      }
      else{
        val = W[x.first] + in2[cur] - x.second;
      }
      if(val > in[x.first]){
        in2[x.first] = in[x.first];
        in[x.first] = val;
        inNode[x.first] = cur;
      }
      else if(val > in2[x.first]){
        in2[x.first] = val;
      }
      dfs2(x.first);
    }
  }
}

void printIn(){
  for(int i=0; i<N; i++){
    cout << i << ": " << in[i] << ", " << in2[i] << " von " << inNode[i] << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> W[i];
  }
  for(int i=0; i<N-1; i++){
    ll u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    G[u].push_back({v, c});
    G[v].push_back({u, c});
  }

  dfs1(0);
  for(int i=0; i<N; i++)
    vis[i] = false;
  dfs2(0);

  ll mx = 0;
  for(int i=0; i<N; i++){
    mx = max(mx, in[i]);
  }

  //printIn();
  cout << mx << endl;
  
  return 0;
}