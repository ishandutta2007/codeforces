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
VI mmc;
string p;
void genpref(){
  if(sz(p)==1){
    mmc={1};
    return;
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
}
VI sola,solb;
VI natl;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>p;
  genpref();
  in n=sz(p);
  natl.resize(n+1);
  forv(i,mmc)
    ++natl[mmc[i]];
  for(in i=n-1;i>=1;--i)
    natl[i]+=natl[i+1];
  for(in i=1;i<=n;++i){
    if(mmc[n-i]==i){
      sola.PB(i);
      solb.PB(natl[i]);
    }
  }
  cout<<sz(sola)<<"\n";
  forv(i,sola)
    cout<<sola[i]<<" "<<solb[i]<<"\n";
  return 0;
}