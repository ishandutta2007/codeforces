#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100005];
int ch[100005];
vector<int> ans;

void dfs(int s,int par,int fir,int sec){
  if(ch[s]^fir){
    ans.push_back(s+1);
    for(auto u: adj[s]){
      if(u != par){
        dfs(u,s,sec,fir^1);  
      }
    }
  }
  else{
    for(auto u: adj[s]){
      if(u != par){
        dfs(u,s,sec,fir);
      }
    }
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    int u,v;
    cin >> u >> v;
    u --;
    v --;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 0; i < n; i++) cin >> ch[i];
  for(int i = 0; i < n; i++){
    int x;cin >> x;
    ch[i] ^= x;
  }
  dfs(0,-1,0,0);
  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}