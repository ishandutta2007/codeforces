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
typedef pair<in,in> PII;
const in mdl=1000000009LL;
VI x,y;
map<PII,in> dcd;
VI stt;
VVI abst;
VVI nup,ndn;
void adp(VI& v, in x, in y){
  if(dcd.find(MP(x,y))==dcd.end())
    return;
  v.PB(dcd[MP(x,y)]);
}
VI usd;
set<in> avb;
void rdst(in id){
  --stt[id];
  in tp;
  forv(i,ndn[id]){
    tp=ndn[id][i];
    if(usd[tp])
      continue;
    --abst[tp][stt[id]+1];
    ++abst[tp][stt[id]];
    if(abst[tp][1])
      avb.erase(tp);
  }
}
void rms(in id){
  avb.erase(id);
  usd[id]=1;
  in tp;
  forv(i,ndn[id]){
    tp=ndn[id][i];
    if(usd[tp])
      continue;
    --abst[tp][stt[id]];
    if(abst[tp][1]==0)
      avb.insert(tp);
  }
  forv(i,nup[id]){
    tp=nup[id][i];
    if(usd[tp])
      continue;
    rdst(tp);
  }
}
VI pw;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  pw.resize(n+3);
  pw[0]=1;
  for(in i=1;i<sz(pw);++i)
    pw[i]=pw[i-1]*n%mdl;
  x.resize(n);
  y.resize(n);
  forn(i,n){
    cin>>x[i]>>y[i];
    dcd[MP(x[i],y[i])]=i;
  }
  stt.resize(n,0);
  abst.resize(n,VI(4,0));
  nup.resize(n);
  ndn.resize(n);
  usd.resize(n,0);
  forn(i,n){
    for(in j=-1;j<=1;++j){
      adp(nup[i],x[i]+j,y[i]+1);
      adp(ndn[i],x[i]+j,y[i]-1);
    }
  }
  forn(i,n)
    stt[i]=sz(ndn[i]);
  forn(i,n){
    forv(j,ndn[i]){
      ++abst[ndn[i][j]][stt[i]];
    }
  }
  in sm=0;
  forn(i,n){
    assert(abst[i][0]==0);
    if(abst[i][1]==0)
      avb.insert(i);
  }
  set<in>::iterator it;
  forn(z,n){
    assert(!avb.empty());
    if(z%2==0){
      it=avb.end();
      --it;
    }
    else
      it=avb.begin();
    sm+=pw[n-1-z]*(*it)%mdl;
    rms(*it);
  }
  sm%=mdl;
  cout<<sm<<endl;
  return 0;
}