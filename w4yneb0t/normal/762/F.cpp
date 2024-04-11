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

VVI egs,egt;
map<in,in> dp;
const in f1=10000;
const in f2=f1*f1;
in rtiso(in u, in pru, in v, in prv){
  if(dp.count(u*f2+pru*f1+v))
    return dp[u*f2+pru*f1+v];
  VI dnv;
  forv(i,egt[v]){
    if(egt[v][i]!=prv)
      dnv.PB(egt[v][i]);
  }
  in n=sz(dnv);
  VVI wyf(sz(egs[u])+1,VI(p2(n)));
  VVI wyb(sz(egs[u]),VI(p2(n)));
  VVI tw(sz(egs[u]),VI(n));
  forv(z,egs[u]){
    forn(j,n)
      tw[z][j]=rtiso(egs[u][z],u,dnv[j],v);
  }
  wyf[0][0]=1;
  forv(i,tw){
    forn(msk,p2(n)){
      wyf[i+1][msk]+=wyf[i][msk];
      wyf[i+1][msk]%=mdl;
      forn(j,n){
	if(msk&p2(j))
	  continue;
	wyf[i+1][msk|p2(j)]+=wyf[i][msk]*tw[i][j];
	wyf[i+1][msk|p2(j)]%=mdl;
      }
    }
  }
  wyb[sz(egs[u])-1][0]=1;
  for(in i=sz(tw)-1;i>0;--i){
    forn(msk,p2(n)){
      wyb[i-1][msk]+=wyb[i][msk];
      wyb[i-1][msk]%=mdl;
      forn(j,n){
	if(msk&p2(j))
	  continue;
	wyb[i-1][msk|p2(j)]+=wyb[i][msk]*tw[i][j];
	wyb[i-1][msk|p2(j)]%=mdl;
      }
    }
  }
  dp[u*f2+u*f1+v]=wyf.back()[p2(n)-1];
  forv(i,tw){
    in sm=0;
    forn(msk,p2(n))
      sm+=wyf[i][msk]*wyb[i][(p2(n)-1)^msk]%mdl;
    sm%=mdl;
    dp[u*f2+egs[u][i]*f1+v]=sm;
  }
  return dp[u*f2+pru*f1+v];
}
in totc(){
  if(sz(egs)==1){
    if(sz(egt)==1)
      return 1;
    return 0;
  }
  in sm=0;
  forv(i,egs){
    sm+=rtiso(i,i,0,0);
  }
  sm%=mdl;
  return sm;
}
void rd(VVI& eg){
  in n;
  cin>>n;
  eg.resize(n);
  in ta,tb;
  forn(z,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    eg[ta].PB(tb);
    eg[tb].PB(ta);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  rd(egs);
  rd(egt);
  in sm=totc();
  dp.clear();
  egs=egt;
  sm*=inv(totc());
  sm%=mdl;
  cout<<sm<<endl;
  return 0;
}