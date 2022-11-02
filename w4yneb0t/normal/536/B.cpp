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
in n,m;
VI poss;
string p;
VI posmc;
VI mmc;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  poss.resize(m);
  cin>>p;
  forn(i,m)
    cin>>poss[i];
  in tmc=0;
  if(m>0){
    tmc+=poss[0]-1;
    in prv=poss[0];
    forv(i,poss){
      if(poss[i]-prv<sz(p))
	posmc.PB(poss[i]-prv);
      else
	tmc+=poss[i]-prv-sz(p);
      prv=poss[i];
    }
    if(n+1-prv>=sz(p))
      tmc+=n+1-prv-sz(p);
  }
  else
    tmc=n;
  in rs=1;
  const in mdl=1000000007LL;
  for(in i=40;i>=0;i--){
    rs*=rs;
    rs%=mdl;
    if(tmc&(1LL<<i)){
      rs*=26;
      rs%=mdl;
    }
  }
  if(sz(p)==1){
    cout<<rs<<endl;
    return 0;
  }
  in rms=1;
  in rsz=0;
  while(rsz<sz(p)-rms && p[rsz+rms]==p[rsz])
    ++rsz;
  mmc.resize(sz(p));
  mmc[0]=sz(p);
  mmc[1]=rsz;
  for(in i=2;i<sz(p);i++){
    mmc[i]=0;
    if(i<rms+rsz){
      mmc[i]=mmc[i-rms];
      if(mmc[i]+i>=rms+rsz)
	mmc[i]=rms+rsz-i;
    }
    if(i+mmc[i]>=rms+rsz){
      rms=i;
      rsz=mmc[i];
      while(rsz<sz(p)-rms && p[rsz+rms]==p[rsz])
	++rsz;
      mmc[i]=rsz;
    }
  }
  bool ok=1;
  forv(i,posmc){
    if(mmc[posmc[i]]+posmc[i]!=sz(p))
      ok=0;
  }
  if(ok)
    cout<<rs<<endl;
  else
    cout<<0<<endl;
  return 0;
}