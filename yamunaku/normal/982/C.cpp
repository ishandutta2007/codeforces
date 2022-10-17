#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

struct node{
  int n;
  bool ok;
};

int main(){
  int n;
  cin >> n;
  vector<list<int>> e(n,list<int>());
  int u,v;
  for(int i=0;i<n-1;i++){
    cin >> u >> v;
    u--;
    v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  stack<struct node> dfs;
  vector<bool> searched(n,false);
  vector<int> parent(n,0),kosuu(n,1);
  dfs.push({0,false});
  searched[0]=true;
  struct node now;
  int ans=0;
  while(!dfs.empty()){
    now=dfs.top();
    dfs.pop();
    if(now.ok){
      for(list<int>::iterator itr=e[now.n].begin();itr!=e[now.n].end();itr++){
        if((*itr)!=parent[now.n]){
          kosuu[now.n]+=kosuu[(*itr)];
        }
      }
      if(kosuu[now.n]%2==0){
        kosuu[now.n]=0;
        ans++;
      }
    }else{
      dfs.push({now.n,true});
      for(list<int>::iterator itr=e[now.n].begin();itr!=e[now.n].end();itr++){
        if(!searched[(*itr)]){
          dfs.push({(*itr),false});
          parent[(*itr)]=now.n;
          searched[(*itr)]=true;
        }
      }
    }
  }
  if(kosuu[0]%2){
    cout << -1 << endl;
  }else{
    cout << ans-1 << endl;
  }
  return 0;
}