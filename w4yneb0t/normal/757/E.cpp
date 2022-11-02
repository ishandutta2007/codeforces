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
const in mdl=1000000007LL;
in p2(in a){
  return (1LL<<a);
}
in pw(in a, in b, in lm=62){
  a%=mdl;
  if(a<0)
    a+=mdl;
  in r=1;
  for(in i=lm;i>=0;--i){
    r=r*r%mdl;
    if(b&p2(i))
      r=r*a%mdl;
  }
  return r;
}
in inv(in a){
  a%=mdl;
  if(a<0)
    a+=mdl;
  assert(a!=0);
  return pw(a,mdl-2,30);
}
VI fc,invfc;
in ncr(in a, in b){
  if(b==0 || b==a)
    return 1;//even if a<0
  if(b<0 || b>a)
    return 0;
  return fc[a]*invfc[b]%mdl*invfc[a-b]%mdl;
}
void inifc(){
  const in mxfc=1001000;
  fc.resize(mxfc);
  invfc.resize(mxfc);
  fc[0]=fc[1]=invfc[0]=invfc[1]=1;
  for(in i=2;i<mxfc;++i){
    fc[i]=fc[i-1]*i%mdl;
    invfc[i]=invfc[mdl%i]*(mdl-mdl/i)%mdl;
  }
  for(in i=2;i<mxfc;++i){
    invfc[i]*=invfc[i-1];
    invfc[i]%=mdl;
  }
}
const in mx=1e6+9;
VI sdv;
VI pms;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  inifc();
  sdv.resize(mx);
  for(in i=2;i<mx;++i){
    if(sdv[i]==0){
      sdv[i]=i;
      pms.PB(i);
    }
    for(in j=0;j<sz(pms) && pms[j]<=sdv[i];++j){
      if(i*pms[j]>=mx)
	break;
      sdv[i*pms[j]]=pms[j];
    }
  }
  in q;
  cin>>q;
  in tn,tr;
  in a;
  in crp,cc;
  forn(zz,q){
    cin>>tr>>tn;
    a=1;
    while(tn>1){
      crp=sdv[tn];
      cc=0;
      while(1){
	tn/=crp;
	++cc;
	if(tn==1 || sdv[tn]!=crp)
	  break;
      }
      a*=(2*ncr(cc+tr,cc)-(tr==0?0:(ncr(cc+tr-1,cc))));
      a%=mdl;
    }
    if(a<0)
      a+=mdl;
    cout<<a<<"\n";
  }
  return 0;
}