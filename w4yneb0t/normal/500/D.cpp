#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<iomanip>
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
in n;
vector<vector<in> > egs,egi;
vector<double> epr,egl;
in ttl;
in dfs(int u, int p){
  int cdn=1;
  in cr;
  forv(i,egs[u]){
    if(egs[u][i]==p)continue;
    cr=dfs(egs[u][i],u);
    cdn+=cr;
    epr[egi[u][i]]=(cr*(cr-1)*(n-cr)+(n-cr)*(n-cr-1)*cr)/double(2LL*ttl);
  }
  return cdn;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  egs.resize(n,vector<in>(0));
  egi=egs;
  epr.resize(n);
  egl.resize(n);
  ttl=(n*(n-1)*(n-2))/6;
  in ta,tb,tl;
  forn(i,n-1){
    cin>>ta>>tb>>tl;
    ta--;
    tb--;
    egs[ta].PB(tb);
    egi[ta].PB(i);
    egs[tb].PB(ta);
    egi[tb].PB(i);
    egl[i]=tl;
  }
  dfs(0,-1);
  double sm=0;
  forn(i,n){
    sm+=epr[i]*egl[i]*2;
  }
  in q;
  cin>>q;
  cout<<setprecision(15);
  forn(i,q){
    cin>>ta>>tl;
    ta--;
    sm-=epr[ta]*egl[ta]*2;
    egl[ta]=tl;
    sm+=epr[ta]*egl[ta]*2;
    cout<<sm<<"\n";
  }
  return 0;
}