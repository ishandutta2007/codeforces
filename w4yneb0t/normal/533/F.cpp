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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
const in mdl=982451653;
in p2(in a){
  return 1LL<<a;
}
in pw(in a, in b){
  in r=1;
  for(in i=30;i>=0;--i){
    r=r*r%mdl;
    if(b&p2(i))
      r=r*a%mdl;
  }
  return r;
}
in inv(in a){
  return pw(a,mdl-2);
}
VI s,t;
VVI isb;
in n,m,p;
in inv2;
in pm;
VI lu;
void proc(in ls, in lt){
  in ht=0;
  in hs=0;
  in cp=1;
  forn(i,m){
    hs+=cp*(s[i]==ls);
    ht+=cp*(t[i]==lt);
    cp*=2;
    cp%=mdl;
  }
  ht%=mdl;
  hs%=mdl;
  if(ht==0)
    return;
  lu[lt]=1;
  forn(i,p){
    if(hs==ht)
      isb[i][lt]=ls;
    hs-=(s[i]==ls);
    hs*=inv2;
    if(i!=p-1)
      hs+=pm*(s[i+m]==ls);
    hs%=mdl;
    if(hs<0)
      hs+=mdl;
  }
}
VI sls;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string ts,tt;
  inv2=inv(2);
  cin>>n>>m>>ts>>tt;
  lu.resize(26);
  pm=pw(2,m-1);
  forn(i,n)
    s.PB(ts[i]-'a');
  forn(i,m)
    t.PB(tt[i]-'a');
  p=n-m+1;
  isb.resize(p,VI(26,-1));
  forn(i,26){
    forn(j,26)
      proc(i,j);
  }
  forn(i,p){
    bool ok=1;
    forn(j,26){
      if(!lu[j])
	continue;
      if(isb[i][j]==-1){
	ok=0;
	continue;
      }
      if(isb[i][j]==j)
	continue;
      if(!lu[isb[i][j]])
	continue;
      if(isb[i][isb[i][j]]!=j)
	ok=0;
    }
    if(ok)
      sls.PB(i+1);
  }
  cout<<sz(sls)<<"\n";
  forv(i,sls)
    cout<<sls[i]<<" ";
  cout<<"\n";
  return 0;
}