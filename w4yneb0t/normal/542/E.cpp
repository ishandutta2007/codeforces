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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VI vis;
VI bst;
VVI egs;
in bb(in u){
  if(vis[u])
    return 0;
  vis[u]=1;
  in mx=bst[u];
  forv(i,egs[u])
    mx=max(mx,bb(egs[u][i]));
  return mx;
}
queue<in> q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  egs.resize(n);
  bst.resize(n);
  vis.resize(n);
  in ta,tb;
  forn(i,m){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  forn(st,n){
    vis[st]=2;
    q.push(st);
    in u,v;
    while(!q.empty()){
      u=q.front();
      bst[u]=max(bst[u],vis[u]-2);
      q.pop();
      forv(i,egs[u]){
	v=egs[u][i];
	if(vis[v]==vis[u]+1 || vis[v]==vis[u]-1)
	  continue;
	if(vis[v]==vis[u]){
	  cout<<-1<<endl;
	  return 0;
	}
	vis[v]=vis[u]+1;
	q.push(v);
      }
    }
    forn(i,n)
      vis[i]=0;
  }
  in sm=0;
  forn(st,n){
    if(vis[st])
      continue;
    sm+=bb(st);
  }
  cout<<sm<<endl;
  return 0;
}