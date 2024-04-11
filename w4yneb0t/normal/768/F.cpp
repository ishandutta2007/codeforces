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
in n(in f, in w, in h){
  if(w==0)
    return 1;
  if(f==0){
    if(w>h)
      return 1;
    return 0;
  }
  ++h;
  in sm=0;
  in ttf;
  forn(sf,2){
    forn(ef,2){
      for(in cw=1;cw*h<=w;++cw){
	ttf=(cw-1)+sf+ef;
	if(ttf>f)
	  break;
	if(ttf==0)
	  continue;
	sm+=ncr(f-ttf+ttf-1,ttf-1)*ncr(w-cw*h+cw-1,cw-1);
	sm%=mdl;
      }
    }
  }
  return sm;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  inifc();
  in f,w,h;
  cin>>f>>w>>h;
  in p=n(f,w,h);
  in q=n(f,w,0);
  cout<<(p*inv(q))%mdl<<endl;
  return 0;
}