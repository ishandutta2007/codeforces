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
map<in,in> cnt;
map<in,in> cbon;
VI val[2];
VI t1,t2;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,l,k;
  scanf("%lld%lld%lld",&n,&l,&k);
  in t;
  in nw=0;
  in sw=1;
  forn(z,n){
    scanf("%lld",&t);
    ++cnt[t];
    if((l-1)%n+1>z)
      ++cbon[t];
    else
      cbon[t];
  }
  fors(i,cnt)
    t1.PB(i->second);
  fors(i,cbon)
    t2.PB(i->second);
  forn(z,2)
    val[z].resize(sz(t1),1-z);
  in ful=(l-1)/n;
  in sm=0;
  in psm;
  in tc;
  for(in z=1;z<=k;++z){
    swap(nw,sw);
    psm=0;
    tc=-1;
    forv(i,val[sw]){
      ++tc;
      psm+=t1[tc]*val[sw][i];
      psm%=mdl;
      sm+=t1[tc]*val[sw][i]%mdl*(max(0LL,ful-z+1)%mdl);
      if(z-1<=ful)
	sm+=val[sw][i]*t2[tc];
      sm%=mdl;
      val[nw][i]=psm;
    }
  }
  sm%=mdl;
  if(sm<0)
    sm+=mdl;
  printf("%lld\n",sm);
  return 0;
}