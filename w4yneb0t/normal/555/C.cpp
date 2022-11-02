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
map<in,in> dcd;
map<in,in> ecd;
VI dr,x,y;
set<pair<in,in> > usd;
struct ttr{
  VI l,r,a;
  in n;
  in qr(in x, in y, in i=1){//find largest i in [0,x) with a[i]<=y
    if(l[i]>x)
      return -1;
    if(a[i]>y)
      return -1;
    if(l[i]==r[i])
      return i-n;
    in t=qr(x,y,2*i+1);
    if(t!=-1)
      return t;
    return qr(x,y,2*i);
  }
  void upd(in x, in y){
    x+=n;
    while(x>=1){
      a[x]=min(a[x],y);
      x/=2;
    }
  }
  void ini(in pn){
    n=pn;
    while(n&(n-1))
      ++n;
    a.resize(2*n,1e9);
    l.resize(2*n);
    r.resize(2*n);
    for(in i=n;i<2*n;++i)
      l[i]=r[i]=i-n;
    for(in i=n-1;i>=1;--i){
      l[i]=l[2*i];
      r[i]=r[2*i+1];
    }
  }
};
ttr ta[2];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,q;
  cin>>n>>q;
  dr.resize(q);
  x.resize(q);
  y.resize(q);
  char c;
  dcd[0]=dcd[n+1]=0;
  forn(z,q){
    cin>>x[z]>>y[z]>>c;
    dr[z]=(c=='U');
    dcd[x[z]]=dcd[y[z]]=0;
  }
  in s=0;
  fors(i,dcd){
    i->second=s;
    ecd[s]=i->first;
    ++s;
  }
  n=s;
  forn(z,2)
    ta[z].ini(n);
  in tp;
  forn(z,2)
    ta[z].upd(0,0);
  forn(z,q){
    x[z]=dcd[x[z]];
    y[z]=dcd[y[z]];
    if(usd.find(MP(x[z],y[z]))!=usd.end()){
      cout<<0<<"\n";
      continue;
    }
    usd.insert(MP(x[z],y[z]));
    if(dr[z]==0){
      tp=ta[0].qr(x[z],y[z]);
      ta[1].upd(y[z],tp);
      cout<<ecd[x[z]]-ecd[tp]<<"\n";
    }
    else{
      tp=ta[1].qr(y[z],x[z]);
      ta[0].upd(x[z],tp);
      cout<<ecd[y[z]]-ecd[tp]<<"\n";
    }
  }
  return 0;
}