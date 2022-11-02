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
const in mx=200009LL;
in h,w,n;
VI r,c;
VI wupt;
VI fc,invfc;
in ncr(in a, in b){
  return fc[a]*invfc[b]%mdl*invfc[a-b]%mdl;
}
in cw(in ccl){
  in& tt=wupt[ccl];
  if(tt!=-1)
    return tt;
  tt=ncr(r[ccl]-1+c[ccl]-1,r[ccl]-1);
  forn(i,n){
    if(i==ccl)continue;
    if(r[i]>r[ccl] || c[i]>c[ccl])
      continue;
    tt-=cw(i)*ncr(r[ccl]-r[i]+c[ccl]-c[i],r[ccl]-r[i]);
    tt%=mdl;
  }
  tt%=mdl;
  tt+=mdl;
  tt%=mdl;
  return tt;
}
in pw(in a, in b){
  in r=1;
  for(in i=40;i>=0;i--){
    r*=r;
    r%=mdl;
    if(b&(1LL<<i)){
      r*=a;
      r%=mdl;
    }
  }
  return r;
}
in inv(in a){
  return pw(a,mdl-2);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  fc.resize(mx);
  fc[0]=1;
  for(in i=1;i<mx;i++)
    fc[i]=fc[i-1]*i%mdl;
  forn(i,mx)
    invfc.PB(inv(fc[i]));
  cin>>h>>w>>n;
  r=c=VI(n);
  forn(i,n)
    cin>>r[i]>>c[i];
  n++;
  r.PB(h);
  c.PB(w);
  wupt=VI(n,-1);
  cout<<cw(n-1)<<endl;
  return 0;
}