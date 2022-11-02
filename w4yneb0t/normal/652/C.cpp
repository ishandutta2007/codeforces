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
VI p,invp;
VI mupt;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  p.resize(n);
  invp.resize(n);
  forn(i,n){
    cin>>p[i];
    --p[i];
    invp[p[i]]=i;
  }
  mupt=VI(n,n-1);
  in ta,tb;
  forn(z,m){
    cin>>ta>>tb;
    --ta;
    --tb;
    ta=invp[ta];
    tb=invp[tb];
    if(tb-1>=ta)
      mupt[ta]=min(mupt[ta],tb-1);
    if(ta-1>=tb)
      mupt[tb]=min(mupt[tb],ta-1);
  }
  for(in i=n-2;i>=0;--i){
    mupt[i]=min(mupt[i],mupt[i+1]);
  }
  in sm=0;
  forn(i,n){
    sm+=mupt[i]-i+1;
  }
  cout<<sm<<endl;
  return 0;
}