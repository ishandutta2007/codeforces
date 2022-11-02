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
in n,m;
VI pr;
VVI cd;
vector<map<in,in> > trp;
VI psf;
VI ent,ext;
VI nnp;
in ord;
void dfs(in u, in dpt){
  ent[u]=ord;
  psf[dpt]^=(1LL<<nnp[u]);
  trp[dpt][ord]=psf[dpt];
  forv(i,cd[u]){
    ++ord;
    dfs(cd[u][i],dpt+1);
  }
  ext[u]=ord;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  cd.resize(n+1);
  pr.resize(n+1);
  pr[1]=1;
  for(in i=2;i<=n;i++){
    cin>>pr[i];
    cd[pr[i]].PB(i);
  }
  nnp.resize(n+1);
  char tr;
  for(in i=1;i<=n;i++){
    cin>>tr;
    nnp[i]=tr-'a';
  }
  ent=ext=VI(n+1);
  psf.resize(n+3,0);
  trp.resize(n+3);
  forv(i,trp)
    trp[i][0]=0;
  ord=1;
  dfs(1,1);
  in v,h;
  string yes="Yes\n";
  string no="No\n";
  map<in,in>::iterator it1,it2;
  in tt;
  forn(zz,m){
    cin>>v>>h;
    it1=trp[h].lower_bound(ent[v]);
    --it1;
    it2=trp[h].upper_bound(ext[v]);
    --it2;
    if(it2->first<ent[v]){
      cout<<yes;continue;
    }
    tt=it2->second^it1->second;
    in cct=0;
    forn(i,28)
      if(tt&(1<<i))
	cct++;
    if(cct<=1)
      cout<<yes;
    else
      cout<<no;
  }
  return 0;
}