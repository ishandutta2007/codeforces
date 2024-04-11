#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
void fl(){
  cout<<-1<<endl;
  exit(0);
}
VVI egs;
VI vis;
void dfs(in u, in l){
  if(vis[u]!=0){
    if(vis[u]!=l)
      fl();
    return;
  }
  vis[u]=l;
  forv(i,egs[u])
    dfs(egs[u][i],-l);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  egs.resize(n+1);
  vis.resize(n+1);
  in ta,tb;
  forn(i,m){
    cin>>ta>>tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  for(in i=1;i<=n;++i){
    if(vis[i]==0)
      dfs(i,1);
  }
  in c1=0;
  for(in i=1;i<=n;++i)
    c1+=(vis[i]==1);
  cout<<c1<<"\n";
  for(in i=1;i<=n;++i){
    if(vis[i]==1)
      cout<<i<<" ";
  }
  cout<<"\n"<<(n-c1)<<"\n";
  for(in i=1;i<=n;++i){
    if(vis[i]==-1)
      cout<<i<<" ";
  }
  cout<<"\n";
  return 0;
}