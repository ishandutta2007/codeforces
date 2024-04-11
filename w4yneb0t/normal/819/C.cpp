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
void ad(map<in,in>& pm, in a){
  for(in i=2;i*i<=a;++i){
    while(a%i==0){
      a/=i;
      ++pm[i];
    }
  }
  if(a>1)
    ++pm[a];
}
map<in,in> pms;
map<in,in> pmn;
in sm;
in n;
VI rpm,rpw;
in nxt,prd;
void dfs(){
  if(nxt==sz(rpm)){
    sm+=(prd<=n);
    return;
  }
  in opr=prd;
  forn(i,rpw[nxt]+1){
    if(i)
      prd*=rpm[nxt];
    ++nxt;
    dfs();
    --nxt;
  }
  prd=opr;
}
VI bd;
in p2(in a){
  return 1LL<<a;
}
in gcd(in a, in b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}
void dot(){
  pms.clear();
  pmn.clear();
  in inp;
  n=1;
  forn(z,3){
    cin>>inp;
    n*=inp;
    ad(pmn,inp);
  }
  in m=1;
  forn(z,3){
    cin>>inp;
    m*=inp;
  }
  ad(pms,2);
  in s=2;
  forn(z,3){
    cin>>inp;
    s*=inp;
    ad(pms,inp);
  }  
  sm=0;
  rpm.clear();
  rpw.clear();
  fors(i,pms){
    rpm.PB(i->first);
    rpw.PB(i->second);
  }
  nxt=0;
  prd=1;
  dfs();  
  bd.clear();
  in tr;
  in ppw;
  fors(i,pmn){
    if(i->second>pms[i->first]){
      tr=1;
      ppw=pms[i->first]+1;
      forn(j,ppw)
	tr*=i->first;
      bd.PB(tr);
    }
  }
  in tn=sz(bd);
  in sig;
  in tprd;
  forn(msk,p2(tn)){
    sig=1;
    tprd=1;
    forn(i,tn){
      if(msk&p2(i)){
	sig=-sig;
	tprd*=bd[i];
      }
    }
    sm+=m/tprd*sig;
  }
  cout<<sm<<endl;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in t;
  cin>>t;
  forn(z,t)
    dot();
  return 0;
}