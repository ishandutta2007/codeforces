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
VI pp;
in rml;
vector<map<in,in> > tdp;
in gcd(in a, in b){
  if(b==0)return a;
  return gcd(b,a%b);
}
in kgv(in a, in b){
  return a*b/gcd(a,b);
}
in dfs(in nxcand, in psf, in fct){
  if(nxcand==sz(pp))
    return rml/psf*fct;
  if(tdp[nxcand].count(psf))
    return tdp[nxcand][psf]*fct;
  in tt=dfs(nxcand+1,psf,fct)+dfs(nxcand+1,kgv(pp[nxcand],psf),-fct);
  tdp[nxcand][psf]=tt*fct;
  return tt;
}
in thav(in ml, set<in> pwhav){
  rml=ml;
  fors(i,pwhav)
    pp.PB(*i);
  tdp.resize(sz(pp));
  return rml-dfs(0,1,1);
}
in n,m,p;
in pw(in a, in b){
  in r=1;
  for(in i=40;i>=0;i--){
    r*=r;
    r%=p;
    if(b&(1LL<<i)){
      r*=a;
      r%=p;
    }
  }
  return r;
}
in ml;
VI pfs;
in invgen;
const in cpow=400;
VI dvpm;
in mpw(in a){
  forv(i,dvpm)
    if(pw(a,dvpm[i])==1)
      return (p-1)/dvpm[i];
  assert(0);
}
set<in> pwhav;
VI a,b;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>p;
  for(in i=1;i*i<=p-1;i++){
    if((p-1)%i==0){
      dvpm.PB(i);
      dvpm.PB((p-1)/i);
    }
  }
  sort(all(dvpm));
  a.resize(n);
  b.resize(m);
  forn(i,n)
    cin>>a[i];
  forn(i,m)
    cin>>b[i];
  in gb=b[0];
  forn(i,m)
    gb=gcd(gb,b[i]);
  gb=gcd(gb,p-1);
  ml=(p-1)/gb;
  in tp=p-1;
  for(in i=2;i*i<=tp;i++){
    if(tp%i==0){
      pfs.PB(i);
      while(tp%i==0)
	tp/=i;
    }
  }
  if(tp!=1)
    pfs.PB(tp);
  forn(i,n){
    in tt=gcd(mpw(a[i]),ml);
    pwhav.insert(tt);
    if(tt==1)break;
  }
  cout<<thav(ml,pwhav)<<endl;
  return 0;
}