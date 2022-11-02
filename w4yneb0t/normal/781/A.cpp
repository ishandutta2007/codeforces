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
VVI egs;
VI dg;
VI clr;
in ncl;
void dfs(in u, in pr, in cu, in cp){
  clr[u]=cu;
  in nc=0;
  forv(i,egs[u]){
    if(egs[u][i]==pr)
      continue;
    while(nc==cu || nc==cp)
      ++nc;
    dfs(egs[u][i],u,nc,cu);
    ++nc;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  egs.resize(n);
  dg.resize(n);
  clr.resize(n);
  in ta,tb;
  forn(z,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
    ++dg[ta];
    ++dg[tb];
  }
  in mxd=0;
  forn(i,n)
    mxd=max(mxd,dg[i]);
  ncl=mxd+1;
  cout<<ncl<<"\n";
  dfs(0,0,0,-1);
  forn(i,n)
    cout<<clr[i]+1<<" ";
  cout<<"\n";
  return 0;
}