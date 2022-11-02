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
VI bdpt;
VI pr;
VI dpt;
in n;
in dfs(in u, in p, in d){
  dpt[u]=d;
  pr[u]=p;
  bdpt[u]=d;
  forv(i,egs[u]){
    if(egs[u][i]==p)
      continue;
    bdpt[u]=max(bdpt[u],dfs(egs[u][i],u,d+1));
  }
  return bdpt[u];
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in x;
  cin>>n>>x;
  egs.resize(n);
  --x;
  in ta,tb;
  forn(z,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  bdpt=pr=dpt=VI(n);
  dfs(0,0,0);
  in gup=(dpt[x]-1)/2;
  in bst=bdpt[x];
  forn(z,gup){
    x=pr[x];
    bst=max(bst,bdpt[x]);
  }
  cout<<2*bst<<endl;
  return 0;
}