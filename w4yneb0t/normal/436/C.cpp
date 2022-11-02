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
vector<vector<string> > bds;
in dbt(in a, in b){
  in sm=0;
  forv(i,bds[a]){
    forv(j,bds[a][i])
      sm+=(bds[a][i][j]!=bds[b][i][j]);
  }
  return sm;
}
VI bdt;
VI prv;
VI usd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m,k,w;
  cin>>n>>m>>k>>w;
  usd.resize(k+1,0);
  prv.resize(k+1,0);
  bdt.resize(k+1,n*m);
  bds.resize(k+1,vector<string>(n));
  for(in z=1;z<=k;++z){
    forn(i,n)
      cin>>bds[z][i];
  }
  VI ansx,ansy;
  in anssm=0;
  forn(zz,k){
    in bst=1e9;
    in bi=-1;
    for(in i=1;i<=k;++i){
      if(usd[i])
	continue;
      if(bdt[i]<bst){
	bst=bdt[i];
	bi=i;
      }
    }
    assert(bi!=-1);
    usd[bi]=1;
    ansx.PB(bi);
    ansy.PB(prv[bi]);
    anssm+=bdt[bi];
    for(in i=1;i<=k;++i){
      if(usd[i])
	continue;
      in tt=dbt(i,bi)*w;
      if(bdt[i]>tt){
	bdt[i]=tt;
	prv[i]=bi;
      }
    }
  }
  cout<<anssm<<"\n";
  forn(z,k)
    cout<<ansx[z]<<" "<<ansy[z]<<"\n";
  return 0;
}