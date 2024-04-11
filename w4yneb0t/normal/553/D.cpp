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
VI tpsol;
double tpbst;
VI st;
VVI egs;
VI isok;
VI bnb;
in n;
double lm;
void tkot(in u){
  if(!isok[u])
    return;
  isok[u]=0;
  in tp;
  forv(i,egs[u]){
    tp=egs[u][i];
    if(!isok[tp])
      continue;
    ++bnb[tp];
    if(sz(egs[tp])*(1-lm)<bnb[tp])
      tkot(tp);
  }
}
bool isp(){
  forn(i,n){
    isok[i]=1;
    bnb[i]=0;
  }
  forv(i,st)
    tkot(st[i]);
  bool isk=0;
  forn(i,n)
    isk|=isok[i];
  if(!isk)
    return 0;
  if(lm>tpbst){
    tpbst=lm;
    tpsol.clear();
    forn(i,n){
      if(isok[i])
	tpsol.PB(i+1);
    }
  }
  return 1;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m,k;
  cin>>n>>m>>k;
  isok.resize(n);
  bnb.resize(n);
  egs.resize(n);
  in ta,tb;
  forn(z,k){
    cin>>ta;
    st.PB(ta-1);
  }
  forn(z,m){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  double mn=-0.01;
  double mx=1.01;
  double md;
  tpbst=mn;
  forn(z,60){
    md=(mx+mn)/2;
    lm=md;
    if(isp())
      mn=md;
    else
      mx=md;
  }
  cout<<sz(tpsol)<<endl;
  forv(i,tpsol){
    cout<<tpsol[i]<<" ";
  }
  cout<<endl;
  return 0;
}