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
const in inf=1e15;
VI pss;
VI mnh[2];
VI ls,le;
map<in,in> decd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,x;
  cin>>n>>x;
  ls=le=VI(n);
  pss.PB(x);
  forn(i,n){
    cin>>ls[i]>>le[i];
    pss.PB(ls[i]);
    pss.PB(le[i]);
  }
  sort(all(pss));
  in ts=0;
  forv(i,pss){
    if(i==0 || pss[i]!=pss[i-1])
      pss[ts++]=pss[i];
  }
  pss.resize(ts);
  forv(i,pss)
    decd[pss[i]]=i;
  x=decd[x];
  forv(i,ls){
    ls[i]=decd[ls[i]];
    le[i]=decd[le[i]];
  }
  forn(z,2)
    mnh[z]=VI(ts,inf);
  in sw=0;
  in nw=0;
  mnh[sw][x]=0;
  forv(z,ls){
    sw=z%2;
    nw=!sw;
    in cmn=inf;
    forn(i,ts){
      cmn=min(cmn,mnh[sw][i]-pss[i]);
      mnh[nw][i]=pss[i]+cmn;
    }
    cmn=inf;
    for(in i=ts-1;i>=0;--i){
      cmn=min(cmn,mnh[sw][i]+pss[i]);
      mnh[nw][i]=min(mnh[nw][i],cmn-pss[i]);
    }
    for(in i=0;i<ls[z];++i)
      mnh[nw][i]+=pss[ls[z]]-pss[i];
    for(in i=le[z]+1;i<ts;++i)
      mnh[nw][i]+=pss[i]-pss[le[z]];
  }
  in rs=inf;
  forn(i,ts)
    rs=min(rs,mnh[nw][i]);
  cout<<rs<<endl;
  return 0;
}